#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) x &(-x)
template <typename T> struct BIT {
    int size;
    vector<T> dat;
    BIT(int n = 0) : size(n), dat(vector<T>(n + 1, 0)) {}
    void add(int i, T x) {
        for (; i <= size; i += lowbit(i))
            dat[i] += x;
    }
    T getSum(int i) {
        T sum = 0;
        for (; i; i -= lowbit(i))
            sum += dat[i];
        return sum;
    }
    T query(int l, int r) { return getSum(r) - getSum(l - 1); }
};