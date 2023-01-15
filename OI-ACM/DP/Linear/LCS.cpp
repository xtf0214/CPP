#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, t;
int solve() {
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
    cout << res << endl;
    return dp[n][m];
}
int main() {
    cin >> n >> m;
    cin >> s >> t;
    cout << solve() << endl;
    return 0;
}