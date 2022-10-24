#include <iostream>
#include <vector>
using namespace std;
template <typename T, T (*op)(T, T), T e>
class SegmentTree
{
private:
    int n;
    vector<T> dat;
    int ls(int p) { return p * 2 + 1; }
    int rs(int p) { return p * 2 + 2; }

public:
    SegmentTree(const vector<T> &arr)
    {
        int len = arr.size();
        n = len & (len - 1) ? 1 << std::__lg(len) + 1 : len;
        dat = vector<T>(2 * n, e);
        copy(arr.begin(), arr.end(), dat.begin() + n - 1);
        for (int p = n - 2; p >= 0; p--)
            dat[p] = op(dat[ls(p)], dat[rs(p)]);
    }
    // 单点修改
    void update(int i, T k)
    {
        dat[i += n - 1] = k;
        for (int p = (i - 1) / 2; p != -1; p = (p - 1) / 2)
            dat[p] = op(dat[ls(p)], dat[(rs(p))]);
    }
    // 区间查询[a,b)
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
T op(T a, T b) { return a + b; }
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 1);
    SegmentTree<int, op, 0> ST(arr);
    cout << ST.query(0, n) << endl;
    return 0;
}