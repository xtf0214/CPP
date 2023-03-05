/**
 * @file    :   P2014
 * @author  :   算法竞赛进阶指南
 * @date    :   2023/03/03 17:18
 * @version :   2023/03/03 17:18
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> val, sz;
vector<vector<int>> G;
vector<vector<int>> f;

void dfs(int u) {
    for (int v : G[u]) {
        dfs(v);
        for (int t = m; t >= 0; t--)
            for (int j = t; j >= 0; j--)
                f[u][t] = max(f[u][t], f[u][t - j] + f[v][j]);
    }
    if (u != 0)
        for (int t = m; t > 0; t--)
            f[u][t] = f[u][t - 1] + val[u];
}
void dfs1(int u) {
    sz[u] = 1;
    for (int v : G[u]) {
        dfs1(v);
        sz[u] += sz[v];
        for (int t = min(m, sz[u]); t >= 0; t--)
            for (int j = min(t, sz[v]); j >= 0; j--)
                f[u][t] = max(f[u][t], f[u][t - j] + f[v][j]);
    }
    if (u != 0)
        for (int t = m; t > 0; t--)
            f[u][t] = f[u][t - 1] + val[u];
}
int main() {
    cin >> n >> m;
    G.resize(n + 1);
    val.resize(n + 1);
    sz.resize(n + 1);
    f.resize(n + 1, vector<int>(m + 1));
    for (int u, v = 1, w; v <= n; v++) {
        cin >> u >> w;
        G[u].push_back(v);
        val[v] = w;
    }
    dfs(0);
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= m; j++)
    //         cerr << f[i][j] << " \n"[j == m];
    cout << f[0][m];
    return 0;
}
/*
0 4 5 9 13
0 2 2 2 2
0 1 3 9 11
0 4 4 4 4
0 1 1 1 1
0 1 1 1 1
0 6 6 6 6
0 2 8 9 9
 */