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
    return dp[n][m];
}
int main() {
    cin >> n >> m;
    cin >> s >> t;
    cout << solve() << endl;
    return 0;
}