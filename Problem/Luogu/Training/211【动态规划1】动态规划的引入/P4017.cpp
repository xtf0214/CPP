// P4017 最大食物链总数
// https://www.luogu.com.cn/problem/P4017
#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
int V, E;
vector<vector<int>> G;
vector<int> indeg, oudeg, dp;
int ans;
int dfs(int u) {
    if (dp[u])
        return dp[u];
    int res = 0;
    for (int v : G[u])
        res = (res + dfs(v)) % mod;
    return dp[u] = res;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> V >> E;
    G.resize(V + 1);
    indeg.resize(V + 1);
    oudeg.resize(V + 1);
    dp.resize(V + 1);
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[v].push_back(u);
        oudeg[u]++;
        indeg[v]++;
    }
    for (int i = 1; i <= V; i++)
        if (indeg[i] == 0)
            dp[i] = 1;
    for (int i = 1; i <= V; i++)
        dfs(i);
    for (int i = 1; i <= V; i++)
        if (oudeg[i] == 0)
            ans = (ans + dp[i]) % mod;
    cout << ans;
    return 0;
}