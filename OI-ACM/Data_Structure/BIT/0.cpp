#include <bits/stdc++.h>
#define lowbit(x) x & -x
using namespace std;
template <typename T>
T op(T a, T b) { return a + b; }
template <typename T>
T rop(T x) { return -x; }
template <typename T, T (*op)(T, T), T (*rop)(T), T e>
class BIT
{
private:
    int n;
    vector<T> dat;

public:
    BIT(int len = 0) { n = len, dat.assign(n + 1, e); }
    void add(int x, int d)
    {
        for (; x <= n; x += lowbit(x))
            dat[x] += d;
    }
    T getSum(int x)
    {
        T res = 0;
        for (; x; x -= lowbit(x))
            res += dat[x]; // dat[i] 保存了lowbit(i)个数
        return res;
    }
    T query(int l, int r) { return getSum(r) - getSum(l - 1); }
};

int main()
{
    int n = 16;
    BIT<int, op, rop, 0> bt(n);
    for (int i = 1; i <= 16; i++)
        bt.add(i, 1);
    cout << bt.query(9, 16);
    return 0;
}