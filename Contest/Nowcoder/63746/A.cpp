/** 
 * @file    :   XOR的艺术
 * @author  :   Tanphoon 
 * @date    :   2023/08/23 17:34
 * @version :   2023/08/23 17:34
 * @link    :   https://ac.nowcoder.com/acm/contest/63746/A
 */
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l = 0, r = 0;
    int dat = 0, tag = 0;
    friend Node operator+(const Node &a, const Node &b) {
        if (a.l == 0 || b.l == 0)
            return a.l ? a : b;
        return Node{a.l, b.r, a.dat + b.dat, 0};
    }
};
template <typename T> class SegmentTree {
    int n;
    vector<Node> tr;
    void build(int p, int l, int r) {
        if (l == r) {
            tr[p].l = l, tr[p].r = r;
        } else {
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
            tr[p] = tr[p << 1] + tr[p << 1 | 1];
        }
    }
    void mark(int p) {
        tr[p].dat = (tr[p].r - tr[p].l + 1) - tr[p].dat;
        tr[p].tag ^= 1;
    }
    void pushdown(int p) {
        if (tr[p].tag) {
            mark(p << 1);
            mark(p << 1 | 1);
            tr[p].tag = 0;
        }
    }

  public:
    SegmentTree(int len) : n(2 << __lg(len - 1)), tr(n << 1) { build(1, 1, n); }
    void modifty(int a, int b, int p = 1) {
        if (tr[p].r < a || b < tr[p].l)
            return;
        if (a <= tr[p].l && tr[p].r <= b)
            return mark(p);
        pushdown(p);
        modifty(a, b, p << 1);
        modifty(a, b, p << 1 | 1);
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    Node query(int a, int b, int p = 1) {
        if (tr[p].r < a || b < tr[p].l)
            return Node();
        if (a <= tr[p].l && tr[p].r <= b)
            return tr[p];
        pushdown(p);
        Node vl = query(a, b, p << 1);
        Node vr = query(a, b, p << 1 | 1);
        return vl + vr;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    SegmentTree<int> seg(n);
    string a;
    cin >> a;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == '1')
            seg.modifty(i, i);
    }
    while (m--) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 0) {
            seg.modifty(l, r);
        } else {
            cout << seg.query(l, r).dat << '\n';
        }
    }
    return 0;
}