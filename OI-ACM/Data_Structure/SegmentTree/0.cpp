#include <iostream>
#include <cmath>
#define op(x, y) x + y
using namespace std;
class SegmentTree
{
private:
    int n;
    int *dat;
    inline int ls(int p) { return p * 2 + 1; }
    inline int rs(int p) { return p * 2 + 2; }

public:
    SegmentTree(int a[], int len)
    {
        n = len & (len - 1) ? 1 << (32 - __builtin_clz(len)) : len;
        // n = 1 << int(ceil(log(len) / log(2)));
        dat = new int[n << 1]{0};
        for (int i = 0; i < len; i++)
            dat[i + n - 1] = a[i];
        for (int p = n - 2; p >= 0; p--)
            dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    // 单点修改
    void update(int k, int a)
    {
        dat[k += n - 1] = a;
        for (int p = (k - 1) / 2; p != -1; p = (p - 1) / 2)
            dat[p] = op(dat[ls(p)], dat[(rs(p))]);
    }
    // 区间查询[a,b]
    int query(int a, int b) { return query(a, b, 0, 0, n); }
    int query(int a, int b, int p, int l, int r)
    {
        if (a >= r || b <= l)
            return 0;
        if (a <= l && b >= r)
            return dat[p];
        int m = (l + r) / 2;
        int vl = query(a, b, ls(p), l, m);
        int vr = query(a, b, rs(p), m, r);
        return op(vl, vr);
    }
};

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = 1;
    SegmentTree T(a, n);
    cout << T.query(0, n) << endl;
    return 0;
}