/**
 * @file    :   C 区间操作
 * @author  :   Tanphoon
 * @date    :   2023/05/19 00:14
 * @version :   2023/05/19 00:14
 * @link    :   https://ac.nowcoder.com/acm/contest/37782/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

template <typename T> class SegmentTree {
    struct Node {
        T dat = 0, tag = 0;
        Node operator+(const Node &t) { return Node{dat + t.dat, 0}; }
    };
    int n;
    vector<Node> tr;
    vector<int> l, r;
    int bCeil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void pushup(int p) { tr[p] = tr[p << 1] + tr[p << 1 | 1]; }
    void mark(T k, int p) {
        tr[p].dat += (r[p] - l[p] + 1) * k;
        tr[p].tag += k;
    }
    void pushdown(int p) {
        if (tr[p].tag) {
            mark(tr[p].tag, p << 1);
            mark(tr[p].tag, p << 1 | 1);
            tr[p].tag = 0;
        }
    }

  public:
    SegmentTree(const vector<T> &v) : n(bCeil(v.size())), tr(n << 1), l(n << 1), r(n << 1) {
        for (int p = n, i = 0; i < v.size(); i++, p++)
            tr[p].dat = v[i];
        for (int p = 2 * n - 1, i = n, d = 1; p; i >>= 1, d <<= 1)
            for (int j = i - 1; j >= 0; j--, p--) {
                l[p] = j * d + 1, r[p] = (j + 1) * d;
                if (p < n)
                    pushup(p);
            }
    }
    void update(int a, int b, T k, int p = 1) {
        if (r[p] < a || b < l[p])
            return;
        if (a <= l[p] && r[p] <= b)
            return mark(k, p);
        pushdown(p);
        update(a, b, k, p << 1);
        update(a, b, k, p << 1 | 1);
        pushup(p);
    }
    Node query(int a, int b, int p = 1) {
        if (r[p] < a || b < l[p])
            return Node();
        if (a <= l[p] && r[p] <= b)
            return tr[p];
        pushdown(p);
        Node vl = query(a, b, p << 1);
        Node vr = query(a, b, p << 1 | 1);
        return vl + vr;
    }
};

int n, q, cnt;
int f[N], st[N], prime[N];
int b[N];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            prime[cnt++] = i, f[i] = 1;
        for (int j = 0; j < cnt && (ll)i * prime[j] <= n; j++) {
            st[i * prime[j]] = 1;
            f[i * prime[j]] = f[i] + 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    init(N);
    for (int i = 1; i <= n; i++)
        cin >> b[i], b[i] = f[b[i]];
    SegmentTree<ll> seg(vector<ll>(b + 1, b + 1 + n));
    cin >> q;
    while (q--) {
        int op, l, r, w;
        cin >> op >> l >> r;
        if (op == 1) {
            cout << seg.query(l, r).dat << '\n';
        } else {
            cin >> w;
            seg.update(l, r, f[w]);
        }
    }
    return 0;
}