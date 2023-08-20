/**
 * @file    :   NodeSegModifty
 * @author  :   Tanphoon
 * @date    :   2023/07/14 01:25
 * @version :   2023/07/14 01:25
 * @link    :   https://www.luogu.com.cn/problem/P3372
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int l = 0, r = 0;
    ll dat = 0, tag = 0;
    friend Node operator+(const Node &a, const Node &b) {
        if (a.l == 0 || b.l == 0)
            return a.l ? a : b;
        return Node{a.l, b.r, a.dat + b.dat, 0};
    }
};
template <typename T> class SegmentTree {
    int n;
    vector<Node> tr;
    const vector<T> &v;
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
    void mark(T k, int p) {
        tr[p].dat += (tr[p].r - tr[p].l + 1) * k;
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
    SegmentTree(const vector<T> &v) : n(2 << __lg(v.size() - 1)), tr(n << 1), v(v) { build(1, 1, n); }
    void modifty(int a, int b, T k, int p = 1) {
        if (tr[p].r < a || b < tr[p].l)
            return;
        if (a <= tr[p].l && tr[p].r <= b)
            return mark(k, p);
        pushdown(p);
        modifty(a, b, k, p << 1);
        modifty(a, b, k, p << 1 | 1);
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
    // void modifty(int a, int b, T k, int p = 1) {
    //     if (a <= tr[p].l && tr[p].r <= b)
    //         return mark(k, p);
    //     pushdown(p);
    //     int mid = (tr[p].l + tr[p].r) >> 1;
    //     if (a <= mid) modifty(a, b, k, p << 1); // 左半区间与修改区间相交
    //     if (b > mid) modifty(a, b, k, p << 1 | 1); // 右半区间与修改区间相交
    //     tr[p] = tr[p << 1] + tr[p << 1 | 1];
    // }
    // Node query(int a, int b, int p = 1) {
    //     if (a <= tr[p].l && tr[p].r <= b)
    //         return tr[p];
    //     pushdown(p);
    //     int mid = (tr[p].l + tr[p].r) >> 1;
    //     if (b <= mid) return query(a, b, p << 1); // 只有左半区间与查询区间相交
    //     else if (a > mid) return query(a, b, p << 1 | 1); // 只有右半区间与查询区间相交
    //     else return query(a, b, p << 1) + query(a, b, p << 1 | 1); // (a <= mid < b) 两端区间都与查询区间相交
    // }
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
        int op, l, r, d;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> d;
            seg.modifty(l, r, d);
        } else
            cout << seg.query(l, r).dat << '\n';
    }
    return 0;
}