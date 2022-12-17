#include <bits/stdc++.h>
using namespace std;
int n, W;
vector<int> w, v;
int rec() {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= W; j++)
            for (int k = 0; j - k * w[i] >= 0; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
    return dp[n][W];
}
int rec1() {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= W; j++)
            if (j - w[i] < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
    return dp[n][W];
}
int rec2() {
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[W];
}
int main() {
    cin >> W >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    cout << rec2() << endl;
    return 0;
}