#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, W;
int w[N], v[N];
int dp[N][N];
// void solve()
// {
//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j <= W; j++)
//         {
//             if (j < w[i])
//                 dp[i][j] = dp[i - 1][j];
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//         }
// }
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
}
int main()
{
    cin >> W >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    solve();
    cout << dp[n][W] << endl;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++)
            cout << dp[i][j] << " \n"[j == W];
}
/*
5 4
2 3
1 2
3 4
2 2*/