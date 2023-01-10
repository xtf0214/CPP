/**
 * @file    :   P1439 【模板】最长公共子序列
 * @author  :   Tanphoon
 * @date    :   2023/01/10 21:19
 * @version :   2023/01/10 21:19
 * @link    :   https://www.luogu.com.cn/problem/P1439
 */
#include <bits/stdc++.h>
using namespace std;
template <typename T> struct PrefixTree {
#define lowbit(x) (x & -x)
    int n;
    vector<T> dat;
    PrefixTree(int _n = 0) : n(_n), dat(vector<T>(_n + 1, 0)) {}
    void add(int i, T x) {
        for (; i <= n; i += lowbit(i))
            dat[i] = max(dat[i], x);
    }
    T get(int i) {
        T res = 0;
        for (; i; i -= lowbit(i))
            res = max(res, dat[i]);
        return res;
    }
};
int n;
vector<int> a;
int solve() {
    int ans = 0;
    vector<int> f(n + 1);
    PrefixTree<int> bt(n);
    for (int i = 1; i <= n; i++) {
        f[i] = bt.get(a[i]) + 1;
        bt.add(a[i], f[i]);
        ans = max(ans, f[i]);
    }
    return ans;
}
int main() {
    cin >> n;
    a.resize(n + 1);
    vector<int> r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1, x; j <= n; j++)
        cin >> x, r[x] = j;
    for (int i = 1; i <= n; i++)
        a[i] = r[a[i]];
    cout << solve();
    return 0;
}