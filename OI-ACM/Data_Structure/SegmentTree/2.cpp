#include <bits/stdc++.h>
using namespace std;
template <typename T, T (*op)(T, T), T e>
class SegmentTree
{
private:
    int n;
    T *dat;
    inline int ls(int p) { return p * 2 + 1; }
    inline int rs(int p) { return p * 2 + 2; }

public:
    SegmentTree(T a[], int len)
    {
        n = len & (len - 1) ? 1 << (32 - __builtin_clz(len)) : len;
        // n = 1 << int(ceil(log(len) / log(2)));
        dat = new T[n << 1];
        fill(dat, dat + (n << 1), e);
        for (int i = 0; i < len; i++)
            dat[i + n - 1] = a[i];
        for (int p = n - 2; p >= 0; p--)
            dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    // 单点修改
    void update(int k, T a)
    {
        dat[k += n - 1] = a;
        for (int p = (k - 1) / 2; p != -1; p = (p - 1) / 2)
            dat[p] = op(dat[ls(p)], dat[(rs(p))]);
    }
    // 区间查询[a,b]
    T query(int a, int b) { return query(a, b, 0, 0, n); }
    T query(int a, int b, int p, int l, int r)
    {
        if (a >= r || b <= l)
            return e;
        if (a <= l && b >= r)
            return dat[p];
        int m = (l + r) / 2;
        T vl = query(a, b, ls(p), l, m);
        T vr = query(a, b, rs(p), m, r);
        return op(vl, vr);
    }
};
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T>
T op(T a, T b) { return gcd(a, b); }

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    SegmentTree<int, op, 0> ST(a, n);
    cout << ST.query(0, n) << endl;
    return 0;
}