#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, W, w[N], v[N], dp[N];

int main()
{
    cin >> n >> W;
    for (int i = 1; i <= n;i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n;i++)
        for (int j = W; j >= w[i];j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[W] << endl;
    return 0;
}