#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e3 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int a[N][N], n, dp[N][N];
void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    solve();
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= i; j++)
    //         cout << dp[i][j] << " \n"[j == i];
    cout << *max_element(dp[n] + 1, dp[n] + n + 1);
    return 0;
}