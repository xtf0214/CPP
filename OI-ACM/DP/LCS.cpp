#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m;
string s, t;
int dp[N][N];
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}
int main()
{
    cin >> n >> m;
    cin >> s >> t;
    solve();
    cout << dp[n][m] << endl;
    return 0;
}