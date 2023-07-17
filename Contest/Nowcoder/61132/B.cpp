/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2023/07/13 17:59
 * @version :   2023/07/13 17:59
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int a[N];
char s[N];

int calc(int a, int b, char o) {
    if (o == '^')
        return a ^ b;
    else if (o == '|')
        return a | b;
    else /* if (o == '&') */
        return a & b;
}

struct Node {
    int l = 0, r = 0;
    int to[21][2];
    friend Node operator+(const Node &a, const Node &b) {
        if (a.l == 0 || b.l == 0)
            return a.l == 0 ? b : a;
        Node c = {a.l, b.r};
        for (int i = 20; ~i; i--)
            for (int t : {0, 1})
                c.to[i][t] = b.to[i][a.to[i][t]];
        return c;
    }
    Node &operator=(int k) {
        for (int i = 20; ~i; i--) {
            int c = k >> i & 1;
            for (auto t : {0, 1}) {
                to[i][t] = calc(t, c, s[l]);
            }
        }
        return *this;
    }
};
template <typename T> class SegmentTree {
    int n;
    vector<Node> tr;
    const int len;
    int bCeil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void build(int p, int l, int r) {
        if (l == r) {
            tr[p].l = l, tr[p].r = r;
            if (l <= len)
                tr[p] = a[l];
        } else {
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
            tr[p] = tr[p << 1] + tr[p << 1 | 1];
        }
    }

  public:
    SegmentTree(int len) : n(bCeil(len)), tr(n << 1), len(len) { build(1, 1, n); }
    void change(int i, T k, int p = 1) {
        if (tr[p].r < i || i < tr[p].l)
            return;
        if (i <= tr[p].l && tr[p].r <= i)
            return void(tr[p] = k);
        change(i, k, p << 1);
        change(i, k, p << 1 | 1);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    Node query(int a, int b, int p = 1) {
        if (tr[p].r < a || b < tr[p].l)
            return Node();
        if (a <= tr[p].l && tr[p].r <= b)
            return tr[p];
        Node vl = query(a, b, p << 1);
        Node vr = query(a, b, p << 1 | 1);
        return vl + vr;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegmentTree<int> seg(n);
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, k;
            cin >> i >> k;
            a[i] = k;
            seg.change(i, k);
        } else {
            int x, l, r;
            cin >> x >> l >> r;
            Node val = seg.query(l, r);
            int res = 0;
            for (int i = 20; ~i; i--)
                res |= val.to[i][x >> i & 1] << i;
            cout << res << '\n';
        }
    }
    return 0;
}