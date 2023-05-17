/**
 * @file    :   g 热身小游戏
 * @author  :   Tanphoon
 * @date    :   2023/05/17 11:05
 * @version :   2023/05/17 11:05
 * @link    :   https://ac.nowcoder.com/acm/contest/37160/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5, mod = 1e9 + 7;
template <typename T> class SegmentTree {
    struct Node {
        T dat = 1, tag = 0;
        Node operator+(const Node &t) { return Node{dat * t.dat % mod, 0}; }
    };
    vector<Node> tr;
    vector<int> l, r;
    int bCeil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void pushup(int p) { tr[p] = tr[p << 1] + tr[p << 1 | 1]; }
    void mark(T k, int p) {
        tr[p].dat = k;
        tr[p].tag = k;
    }
    void pushdown(int p) {
        if (tr[p].tag) {
            mark(tr[p].tag, p << 1);
            mark(tr[p].tag, p << 1 | 1);
            tr[p].tag = 0;
        }
    }

  public:
    int n;
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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q;
    SegmentTree<ll> seg(vector<ll>(N, 1));
    for (int i = 1; i <= q; i++) {
        int op, l, r;
        ll a;
        cin >> op;
        if (op == 1) {
            cin >> a;
            seg.update(i, i, a);
        } else if (op == 2) {
            cin >> l >> r;
            seg.update(l, r, 1);
        } else {
            cout << seg.query(1, seg.n).dat << '\n';
        }
    }
    return 0;
}