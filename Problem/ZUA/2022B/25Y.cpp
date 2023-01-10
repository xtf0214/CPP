// 1041 Problem  Y	01背包问题（第五讲）
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, W;
int w[N], v[N];
int dp[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
}
int main()
{
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    solve();
    cout << dp[W] << endl;
}
