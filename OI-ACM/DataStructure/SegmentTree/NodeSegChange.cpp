/**
 * @file    :   NodeSegChange
 * @author  :   Tanphoon
 * @date    :   2023/07/14 01:25
 * @version :   2023/07/14 01:25
 * @link    :   https://www.luogu.com.cn/problem/P3374
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int l = 0, r = 0;
    ll dat = 0;
    friend Node operator+(const Node &a, const Node &b) {
        if (a.l == 0 || b.l == 0)
            return a.l == 0 ? b : a;
        return Node{a.l, b.r, a.dat + b.dat};
    }
};
template <typename T> class SegmentTree {
    int n;
    vector<Node> tr;
    const vector<T> &v;
    int bCeil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void build(int p, int l, int r) {
        if (l == r) {
            tr[p].l = l, tr[p].r = r;
            if (l <= v.size())
                tr[p].dat = v[l - 1];
        } else {
            int m = (l + r) >> 1;
            build(p << 1, l, m);
            build(p << 1 | 1, m + 1, r);
            tr[p] = tr[p << 1] + tr[p << 1 | 1];
        }
    }

  public:
    SegmentTree(const vector<T> &v) : n(bCeil(v.size())), tr(n << 1), v(v) { build(1, 1, n); }
    void change(int i, T k, int p = 1) {
        if (tr[p].r < i || i < tr[p].l)
            return;
        if (i <= tr[p].l && tr[p].r <= i)
            return void(tr[p].dat += k);
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
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    SegmentTree<ll> seg(arr);
    while (m--) {
        int op, l, r, x, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> k;
            seg.change(x, k);
        } else {
            cin >> l >> r;
            cout << seg.query(l, r).dat << '\n';
        }
    }
    return 0;
}