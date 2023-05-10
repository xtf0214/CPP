/**
 * @file    :   P3372 【模板】线段树 1
 * @author  :   Tanphoon
 * @date    :   2023/05/05 23:37
 * @version :   2023/05/05 23:37
 * @link    :   https://www.luogu.com.cn/problem/P3372
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, T (*op)(T, T), T (*e)()> class SegmentTree {
    int n;
    vector<T> dat, tag;
    int bit_ceil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void mark(int k, int p, int l, int r) {
        dat[p] += (r - l + 1) * k;
        tag[p] += k;
    }
    void push_down(int p, int l, int r) {
        if (tag[p]) {
            int m = (l + r) >> 1;
            mark(tag[p], p << 1, l, m);
            mark(tag[p], p << 1 | 1, m + 1, r);
            tag[p] = 0;
        }
    }

  public:
    SegmentTree(vector<T> &v) : n(bit_ceil(v.size())), dat(n << 1, e()), tag(n << 1) {
        copy(v.begin(), v.end(), dat.begin() + n);
        for (int p = n - 1; p; p--)
            dat[p] = op(dat[p << 1], dat[p << 1 | 1]);
    }
    void update(int a, int b, int k) { return update(a, b, k, 1, 1, n); }
    void update(int a, int b, int k, int p, int l, int r) {
        if (r < a || b < l)
            return;
        if (a <= l && r <= b)
            return mark(k, p, l, r);
        push_down(p, l, r);
        int m = (l + r) >> 1;
        update(a, b, k, p << 1, l, m);
        update(a, b, k, p << 1 | 1, m + 1, r);
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    SegmentTree<ll, Add, e> seg(a);
    while (m--) {
        int op, l, r, k;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> k;
            seg.update(l, r, k);
        } else if (op == 2) {
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}