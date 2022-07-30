#include <bits/stdc++.h>
using namespace std;
template <typename T, T (*op)(T, T), T e>
class SegmentTree
{
private:
    int n;
    vector<T> dat, tag;
    int ls(int p) { return p << 1; }
    int rs(int p) { return p << 1 | 1; }
    void mark(int p, int l, int r, int k) { tag[p] = k, dat[p] = k; }
    void push_down(int p, int l, int r)
    {
        int m = (l + r) >> 1;
        mark(ls(p), l, m, 1);
        mark(rs(p), m + 1, r, 1);
        tag[p] = 0;
    }

public:
    SegmentTree(const vector<T> &arr)
    {
        int len = arr.size();
        n = len & (len - 1) ? 1 << std::__lg(len) + 1 : len;
        dat.assign(2 * n, e);
        tag.assign(2 * n, e);
        copy(arr.begin(), arr.end(), dat.begin() + n);
        for (int i = n - 1; i >= 1; i--)
            dat[i] = op(dat[ls(i)], dat[rs(i)]);
    }
    T &operator[](int i) { return dat[i + n - 1]; }
    void update(int i, int k) { update(i, i, k, 1, 1, n); }
    void update(int s, int t, int k) { update(s, t, k, 1, 1, n); }
    void update(int s, int t, int k, int p, int l, int r)
    {
        if (s <= l && r <= t)
            return mark(p, l, r, k);
        if (tag[p])
            push_down(p, l, r);
        int m = (l + r) >> 1;
        if (s <= m)
            update(s, t, k, ls(p), l, m);
        if (t > m)
            update(s, t, k, rs(p), m + 1, r);
        dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    T query(int s, int t) { return query(s, t, 1, 1, n); }
    T query(int s, int t, int p, int l, int r)
    {
        if (s > r || t < l)
            return e;
        if (s <= l && r <= t)
            return dat[p];
        if (tag[p])
            push_down(p, l, r);
        int m = (l + r) >> 1;
        T vl = query(s, t, ls(p), l, m);
        T vr = query(s, t, rs(p), m + 1, r);
        return op(vl, vr);
    }
};
template <typename T>
T op(T a, T b) { return a * b; }
int main()
{
    ios::sync_with_stdio(false);
    int n = 8, m = 8;
    cin >> n >> m;
    vector<long long> arr(n, 1);
    SegmentTree<long long, op, 1> seg(arr);
    for (int i = 1; i <= n; i++)
    {
        int opt, l, r, d;
        cin >> opt >> l >> r;
        if (opt == 0)
            cin >> d, seg.update(l, r, d);
        else
            cout << seg.query(l, r) << endl;
    }
    return 0;
}