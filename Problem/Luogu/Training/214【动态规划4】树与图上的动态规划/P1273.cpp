/**
 * @file    :   P1273 有线电视网
 * @author  :   Tanphoon
 * @date    :   2023/03/06 17:16
 * @version :   2023/03/10 01:49
 */
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<vector<pii>> G;
vector<int> val, sz; // sz[u]:u子树的叶节点个数
vector<vector<int>> f;

void dfs(int u) {
    f[u][0] = 0;
    sz[u] = 0;
    if (u > n - m) {
        f[u][1] = val[u];
        sz[u] = 1;
    }
    for (auto &[v, w] : G[u]) {
        dfs(v);
        sz[u] += sz[v];
        for (int j = min(m, sz[u]); j >= 1; j--)
            for (int k = 0; k <= min(j, sz[v]); k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k] - w);
    }
}
int main() {
    cin >> n >> m;
    G.resize(n + 1);
    val.resize(n + 1);
    sz.resize(n + 1);
    f.assign(n + 1, vector<int>(m + 10, -0x3f3f3f3f));
    for (int u = 1; u <= n - m; u++) {
        int k, v, w;
        cin >> k;
        while (k--) {
            cin >> v >> w;
            G[u].push_back({v, w});
        }
    }
    for (int u = n - m + 1; u <= n; u++)
        cin >> val[u];
    dfs(1);
    for (int i = m; i >= 1; i--)
        if (f[1][i] >= 0) {
            cout << i;
            break;
        }
    return 0;
}