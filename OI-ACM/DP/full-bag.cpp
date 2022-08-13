#include <iostream>
using namespace std;
const int N = 1e3 + 5;
int n, W, w[N], v[N];
long long f[N];
// long long dp[N][N];
// void solve1()
// {
//     for (int i = 1; i <= n;i++)
//         for (int j = 0; j <= W;j++)
//             for (int k = 0; k * w[i] <= j;k++)
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + v[i]);
// }
// void solve2()
// {
//     for (int i = 1; i <= n;i++)
//         for (int j = w[i]; j <= W;j++)
//             dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
// }
long long dp[N];
void solve3()
{
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= W; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
}
int main()
{
    cin >> W >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    solve3();
    cout << dp[W];
    return 0;
}