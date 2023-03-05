/**
 * @file    :   P2014
 * @author  :   https://oi-wiki.org/dp/tree/#%E6%A0%91%E4%B8%8A%E8%83%8C%E5%8C%85
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
    f[u][1] = val[u];
    sz[u] = 1;
    for (int v : G[u]) {
        dfs(v);
        sz[u] += sz[v];
        // 注意下面两重循环的上界和下界
        // 只考虑已经合并过的子树，以及选的课程数超过 m+1 的状态没有意义
        for (int i = min(sz[u], m + 1); i; i--)
            for (int j = 1; j <= sz[u] && i + j <= m + 1; j++)
                f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j]);
    }
}
int main() {
    cin >> n >> m;
    G.resize(n + 1);
    val.resize(n + 1);
    sz.resize(n + 1);
    f.resize(n + 1, vector<int>(m + 2));
    for (int u, v = 1, w; v <= n; v++) {
        cin >> u >> w;
        G[u].push_back(v);
        val[v] = w;
    }
    dfs(0);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m + 1; j++)
            cerr << f[i][j] << " \n"[j == m + 1];
    cout << f[0][m + 1];
    return 0;
}
/*
0 0 4 5 9 13
0 2 0 0 0 0
0 1 3 9 11 12
0 4 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 6 0 0 0 0
0 2 8 9 8 3
*/