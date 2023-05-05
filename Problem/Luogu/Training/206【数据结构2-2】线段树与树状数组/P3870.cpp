/**
 * @file    :   P3870 [TJOI2009] 开关
 * @author  :   Tanphoon
 * @date    :   2023/05/05 23:37
 * @version :   2023/05/05 23:37
 * @link    :   https://www.luogu.com.cn/problem/P3870
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, T (*op)(T, T), T (*e)()> class SegmentTree {
    int n;
    vector<T> dat, tag;
    int bit_ceil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void mark(int p, int l, int r) {
        dat[p] = (r - l + 1) - dat[p];
        tag[p] ^= 1; // 区间标记，表示这个区间的开关要推一下。如果推两次，变回原来的样子
    }
    void push_down(int p, int l, int r) {
        if (tag[p]) { // 如果需要推一下开关
            int m = (l + r) >> 1;
            mark(p << 1, l, m);
            mark(p << 1 | 1, m + 1, r);
            tag[p] = 0;
        }
    }

  public:
    SegmentTree(int _n) : n(bit_ceil(_n)), dat(n << 1, e()), tag(n << 1) {}
    SegmentTree(vector<T> &v) : n(bit_ceil(v.size())), dat(n << 1, e()), tag(n << 1) {
        copy(v.begin(), v.end(), dat.begin() + n);
        for (int p = n - 1; p; p--)
            dat[p] = op(dat[p << 1], dat[p << 1 | 1]);
    }
    void update(int a, int b) { return update(a, b, 1, 1, n); }
    void update(int a, int b, int p, int l, int r) {
        if (r < a || b < l)
            return;
        if (a <= l && r <= b)
            return mark(p, l, r);
        push_down(p, l, r);
        int m = (l + r) >> 1;
        update(a, b, p << 1, l, m);
        update(a, b, p << 1 | 1, m + 1, r);
        dat[p] = op(dat[p << 1], dat[p << 1 | 1]);
    }
    T query(int a, int b) { return query(a, b, 1, 1, n); }
    T query(int a, int b, int p, int l, int r) {
        if (r < a || b < l)
            return e();
        if (a <= l && r <= b)
            return dat[p];
        push_down(p, l, r);
        int m = (l + r) >> 1;
        T vl = query(a, b, p << 1, l, m);
        T vr = query(a, b, p << 1 | 1, m + 1, r);
        return op(vl, vr);
    }
};
template <typename T> T Add(T a, T b) { return a + b; }
template <typename T> T e() { return 0; }
int main() {
    int n, m;
    cin >> n >> m;
    SegmentTree<int, Add, e> seg(n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 0) {
            seg.update(l, r);
        } else if (op == 1) {
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}