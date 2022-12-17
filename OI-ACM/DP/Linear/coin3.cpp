#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, W;
vector<int> a;
int rec() {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++)
            if (w - a[i] < 0)
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w] + dp[i][w - a[i]];
    }
    return dp[n][W];
}
int rec2() {
    vector<int> dp(W + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int w = a[i]; w <= W; w++)
            dp[w] = dp[w] + dp[w - a[i]];
    return dp[W];
}
int main() {
    cin >> n >> W;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << rec();
    return 0;
}