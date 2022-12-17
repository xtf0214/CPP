// P1216 数字三角形
// https://www.luogu.com.cn/problem/P1216
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

int n;
vector<vector<int>> a;
// dfs搜索
int dfs(int i, int j) {
    if (i == n)
        return a[i][j];
    return max(dfs(i + 1, j), dfs(i + 1, j + 1)) + a[i][j];
}
// 记忆化搜索
vector<vector<int>> dp;
int dfsmem(int i, int j) {
    if (i == n)
        return dp[i][j] = a[i][j];
    if (dp[i][j] != INF)
        return dp[i][j];
    return dp[i][j] = max(dfs(i + 1, j), dfs(i + 1, j + 1)) + a[i][j];
}
// 线性递推
int rec() {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    for (int j = 1; j <= n; j++)
        dp[n][j] = a[n][j];
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
    return dp[1][1];
}
int main() {
    cin >> n;
    a.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    int ans;
    // // dfs搜索
    ans = dfs(1, 1);

    // // 记忆化搜索
    dp.assign(n + 1, vector<int>(n + 1, INF));
    ans = dfsmem(1, 1);

    // 递推
    ans = rec();

    cout << ans << endl;
    return 0;
}