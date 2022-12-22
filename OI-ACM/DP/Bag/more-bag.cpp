#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, W;
vector<int> w, v, c;

int rec() {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= W; j++)
            for (int k = 0; j - k * w[i] >= 0 && k <= c[i]; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
    return dp[n][W];
}
int rec1() {
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
            for (int k = 1; j - k * w[i] >= 0 && k <= c[i]; k++)
                dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
    return dp[W];
}
int rec2() {
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= c[i]; k++)
            for (int j = W; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[W];
}

int rec3() {
    vector<int> dp(W + 1);
    vector<pii> a;
    for (int i = 1; i <= n; i++) {
        int x = c[i];
        for (int bin = 1; x > bin; x -= bin, bin <<= 1)
            a.push_back({w[i] * bin, v[i] * bin});
        a.push_back({w[i] * x, v[i] * x});
    }
    for (auto &[w, v] : a)
        for (int j = W; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    return dp[W];
}
int main() {
    cin >> W >> n;
    w.resize(n + 1);
    v.resize(n + 1);
    c.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i] >> c[i];
    cout << rec3();
    return 0;
}
/*
5 4
2 3 2
1 2 3
3 4 1
2 2 2
 */