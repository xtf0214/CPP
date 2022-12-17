#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

int n, W;
vector<int> a;
// dfs搜索
int dfs(int w) {
    if (w == 0)
        return 0;
    if (w < 0)
        return INF;
    int res = INF;
    for (int i = 0; i < n; i++)
        res = min(res, dfs(w - a[i]) + 1);
    return res;
}
// 记忆化搜索
vector<int> dp;
int dfsmem(int w) {
    if (w < 0)
        return INF;
    if (dp[w] != INF)
        return dp[w];
    int res = INF;
    for (int i = 0; i < n; i++)
        res = min(res, dfsmem(w - a[i]) + 1);
    return dp[w] = res;
}
// 线性递推
int rec() {
    vector<int> dp(W + 1, INF);
    dp[0] = 0;
    for (int w = 1; w <= W; w++)
        for (int i = 0; i < n; i++)
            if (w - a[i] >= 0)
                dp[w] = min(dp[w], dp[w - a[i]] + 1);
    return dp[W];
}
int main() {
    cin >> n >> W;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans;
    // // dfs搜索
    // ans = dfs(W);

    // // 记忆化搜索
    // dp.assign(W+1, INF);
    // dp[0] = 0;
    // ans = dfsmem(W);

    // 递推
    // ans = rec();

    cout << ans << endl;
    return 0;
}