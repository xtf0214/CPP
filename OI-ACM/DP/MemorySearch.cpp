#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, W;
int w[N], v[N];
int rec(int i, int j)
{
    int res;
    if (i == n)
        res = 0;
    else if (j < w[i])
        res = rec(i + 1, j);
    else
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    return res;
}
int dp[N][N];
int recDP(int i, int j)
{
    if (dp[i][j] >= 0)
        return dp[i][j];
    int res;
    if (i == n)
        res = 0;
    else if (j < w[i])
        res = recDP(i + 1, j);
    else
        res = max(recDP(i + 1, j), recDP(i + 1, j - w[i]) + v[i]);
    return dp[i][j] = res;
}
int main()
{
    cin >> W >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << recDP(0, W);
    return 0;
}