/**
 * @file    :   旅行商问题
 * @author  :   Tanphoon
 * @date    :   2024/06/07 23:33
 * @version :   2024/06/07 23:33
 */
#include <bits/stdc++.h>
using namespace std;
#include <DEBUG.h>
const int INF = 1e9;
int n, m;
vector<vector<int>> G, dp;
// dp[S][u] 表示从 u 出发到 剩余的所有顶点（v \notin S） 最终回到顶点 0 的最小路径长度
int rec(int S = 0, int u = 0) {
    if (dp[S][u] >= 0)
        return dp[S][u];
    if (S == (1 << n) - 1 && u == 0)
        return dp[S][u] = 0;
    int res = INF;
    for (int v = 0; v < n; v++)
        if (!(S >> v & 1) && G[u][v])
            res = min(res, rec(S | 1 << v, v) + G[u][v]);
    return dp[S][u] = res;
}
int rec2() {
    dp.assign(1 << n, vector<int>(n, INF));
    dp[(1 << n) - 1][0] = 0;
    for (int S = (1 << n) - 2; S >= 0; S--)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (!(S >> v & 1) && G[u][v])
                    dp[S][u] = min(dp[S][u], dp[S | 1 << v][v] + G[u][v]);
    return dp[0][0];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    dp.assign(1 << n, vector<int>(n, -1));
    G.assign(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
    }
    cout << rec() << '\n';
    cout << rec2() << '\n';
    return 0;
}
/*
5 8
0 1 3
0 3 4
1 2 5
2 0 4
2 3 5
3 4 3
4 0 7
4 1 6
 */