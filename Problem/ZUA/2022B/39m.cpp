/**
 * @file    :   39m 最大公共子序列（动态规划）
 * @author  :   Tanphoon
 * @date    :   2023/01/15 11:05
 * @version :   2023/01/15 11:05
 */
#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, t;
void solve() {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    string res;
    for (int i = n, j = m; i >= 1; i--) {
        while (j > 1 && dp[i][j] == dp[i][j - 1])
            j--;
        if (dp[i][j] != dp[i][j - 1] && dp[i][j] != dp[i - 1][j])
            res.push_back(s[i - 1]);
    }
    reverse(res.begin(), res.end());
    cout << res << " " << dp[n][m];
}
int main() {
    cin >> s >> t;
    n = s.size(), m = t.size();
    solve();
    return 0;
}