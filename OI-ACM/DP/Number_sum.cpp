#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,K;
int a[N], m[N];
bool dp[N][N];

void solve()
{
    dp[0][0] = true;
    for (int i = 0; i < n;i++)
        for (int j = 0; j <= K;j++)
            for (int k = 0; k <= m[i] && k * a[i] <= j;k++)
                dp[i + 1][j] |= dp[i][j - k * a[i]];
    dp[n][K] ? puts("Yes\n") : puts("No\n");
}
int main()
{
    
    return 0;
}