/**
 * @file    :   P2015 二叉苹果树
 * @author  :   Tanphoon
 * @date    :   2023/02/27 20:34
 * @version :   2023/03/02 10:21
 * @link    :   https://www.luogu.com.cn/problem/P2015
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<vector<pii>> G;
vector<vector<int>> f; // f[u][j]: 在以u为根的树上留j个树枝
vector<int> sz;        // 以i为根的树的树枝个数

void dfs(int u, int fa) {
    for (auto &[v, w] : G[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        sz[u] += sz[v] + 1;
        for (int j = min(sz[u], m); j; j--)
            for (int k = 0; k <= min(j - 1, sz[v]); k++)
                f[u][j] = max(f[u][j], f[u][j - 1 - k] + f[v][k] + w);
    }
}
int main() {
    cin >> n >> m;
    G.resize(n + 1);
    f.resize(n + 1, vector<int>(m + 1));
    sz.resize(n + 1);
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << f[1][m];
    return 0;
}