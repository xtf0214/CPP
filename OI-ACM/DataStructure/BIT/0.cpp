#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BIT {
#define lowbit(x) x & (-x)
    int size;
    vector<T> dat;
    BIT(int n = 0) : size(n), dat(n + 1, 0) {}
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