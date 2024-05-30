/** 
 * @file    :   树状数组基础
 * @author  :   Tanphoon
 * @date    :   2024/05/30 10:53
 * @version :   2024/05/30 10:53
 * @link    :   https://www.luogu.com.cn/problem/P3374
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BIT {
    int n;
    vector<T> tr;
    BIT(int _n = 0) : n(_n), tr(n + 1, 0) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, T x) {
        for (assert(i > 0); i <= n; i += lowbit(i))
            tr[i] += x;
    }
    T ask(int i) {
        T res = 0;
        for (i = min(i, n); i; i -= lowbit(i))
            res += tr[i];
        return res;
    }
};