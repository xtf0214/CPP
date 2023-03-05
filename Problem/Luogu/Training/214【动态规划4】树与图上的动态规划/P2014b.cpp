/**
 * @file    :   P2014
 * @author  :   https://www.cnblogs.com/ifmyt/p/9588872.html
 * @date    :   2023/03/03 17:18
 * @version :   2023/03/03 17:18
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> val;
vector<vector<int>> G;
vector<vector<int>> f;

void dfs(int u, int w) {
    if (w <= 0)
        return;
    for (int v : G[u]) {
        for (int k = 0; k < w; ++k)
            f[v][k] = f[u][k] + val[v];
        dfs(v, w - 1);
        for (int k = 1; k <= w; ++k)
            f[u][k] = max(f[u][k], f[v][k - 1]);
    }
}
int main() {
    cin >> n >> m;
    G.resize(n + 1);
    val.resize(n + 1);
    f.resize(n + 1, vector<int>(m + 1));
    for (int u, v = 1, w; v <= n; v++) {
        cin >> u >> w;
        G[u].push_back(v);
        val[v] = w;
    }
    dfs(0, m);
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= m; j++)
    //         cerr << f[i][j] << " \n"[j == m];
    cout << f[0][m];
    return 0;
}
/*
0 4 5 9 13
3 3 3 0 0
1 3 9 11 0
4 5 7 13 0
2 4 4 0 0
4 6 0 0 0
9 11 0 0 0
3 9 11 0 0
 */