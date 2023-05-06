#include <bits/stdc++.h>
using namespace std;
template <typename T, T (*op)(T, T), T (*e)()> class SegmentTree {
    int n;
    vector<T> dat, tag;
    int ls(int p) { return p << 1; }
    int rs(int p) { return p << 1 | 1; }
    int bCeil(int n) { return 1 << 32 - __builtin_clz(n - 1); }
    void mark(int p, int l, int r, int k) { tag[p] += k, dat[p] += k * (r - l + 1); }
    void push_down(int p, int l, int r) {
        if (tag[p]) {
            int m = (l + r) >> 1;
            mark(ls(p), l, m, tag[p]);
            mark(rs(p), m + 1, r, tag[p]);
            tag[p] = 0;
        }
    }

  public:
    SegmentTree(const vector<T> &v) : n(bCeil(v.size())), dat(2 * n, e()), tag(2 * n) {
        copy(v.begin(), v.end(), dat.begin() + n);
        for (int i = n - 1; i >= 1; i--)
            dat[i] = op(dat[ls(i)], dat[rs(i)]);
    }
    void update(int i, int k) { update(i, i, k, 1, 1, n); }
    void update(int a, int b, int k) { update(a, b, k, 1, 1, n); }
    void update(int a, int b, int k, int p, int l, int r) {
        if (r < a || b < l)
            return;
        if (a <= l && r <= b)
            return mark(p, l, r, k);
        push_down(p, l, r);
        int m = (l + r) >> 1;
        update(a, b, k, ls(p), l, m);
        update(a, b, k, rs(p), m + 1, r);
        dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    T query(int a, int b) { return query(a, b, 1, 1, n); }
    T query(int a, int b, int p, int l, int r) {
        if (r < a || b < l)
            return e();
        if (a <= l && r <= b)
            return dat[p];
        push_down(p, l, r);
        int m = (l + r) >> 1;
        T vl = query(a, b, ls(p), l, m);
        T vr = query(a, b, rs(p), m + 1, r);
        return op(vl, vr);
    }
};
template <typename T> T Add(T a, T b) { return a + b; }
template <typename T> T e() { return 0; }
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    SegmentTree<long long, Add, e> seg(arr);
    while (m--) {
        int op, l, r, d;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> d;
            seg.update(l, r, d);
        } else
            cout << seg.query(l, r) << '\n';
    }
    return 0;
}