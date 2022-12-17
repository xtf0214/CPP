#include <bits/stdc++.h>
using namespace std;
int n, W;
vector<int> w, v;
int rec() {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= W; j++)
            if (j - w[i] < 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
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
    w.resize(n + 1);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    cout << rec() << endl;
}
/*
5 4
2 3
1 2
3 4
2 2*/