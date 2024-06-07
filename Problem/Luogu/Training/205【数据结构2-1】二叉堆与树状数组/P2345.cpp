/**
 * @file    :   P2345 [USACO04OPEN] MooFest G
 * @author  :   Tanphoon
 * @date    :   2024/06/08 01:37
 * @version :   2024/06/08 01:37
 * @link    :   https://www.luogu.com.cn/problem/P2345
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e4 + 5;
template <typename T> struct BIT {
    int n;
    vector<T> dat;
    BIT(int n = 0) : n(n), dat(n + 1, T()) {}
    inline int lowbit(int x) { return x & -x; }
    void add(int i, T x) {
        for (assert(i > 0); i <= n; i += lowbit(i))
            dat[i] += x;
    }
    T get(int i) {
        T res = 0;
        for (i = min(i, n); i; i -= lowbit(i))
            res += dat[i];
        return res;
    }
    T rangeQuery(int l, int r) { return get(r) - get(l - 1); }
};
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    BIT<int> cnt(N);
    BIT<ll> sum(N);
    for (int i = 0; i < n; i++)
        cin >> vp[i].first >> vp[i].second;
    sort(vp.begin(), vp.end());
    ll ans = 0;
    for (auto [v, x] : vp) {
        int cntl = cnt.rangeQuery(1, x - 1);
        int cntr = cnt.rangeQuery(x + 1, N);
        ll suml = sum.rangeQuery(1, x - 1);
        ll sumr = sum.rangeQuery(x + 1, N);
        ans += (ll)v * (sumr - cntr * x);
        ans += (ll)v * (cntl * x - suml);
        cnt.add(x, 1);
        sum.add(x, x);
    }
    cout << ans << '\n';
    return 0;
}