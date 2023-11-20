/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/11/20 13:38
 * @version :   2023/11/20 13:38
 * @link    :   https://ac.nowcoder.com/acm/contest/903/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif

inline void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    vector dp(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> f = [&](int l, int r) {
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        if (l == r)
            return dp[l][r] = 0;
        int res = INT_MAX;
        for (int k = l; k <= r; k++) {
            res = min(res, f(l, k - 1) + f(k + 1, r) + (r - l) * w[k]);
        }
        return dp[l][r] = res;
    };
    cout << f(1, n) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}