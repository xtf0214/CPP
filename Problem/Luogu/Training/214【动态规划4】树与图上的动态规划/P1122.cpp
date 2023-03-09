/**
 * @file    :   P1122 最大子树和
 * @author  :   Tanphoon
 * @date    :   2023/03/10 01:58
 * @version :   2023/03/10 01:58
 * @link    :   https://www.luogu.com.cn/problem/P1122
 */
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<vector<int>> G;
vector<int> f, w;

void dfs(int u, int fa) {
    f[u] = w[u];
    for (int v : G[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        if (f[v] > 0)
            f[u] += f[v];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    G.resize(n + 1);
    f.resize(n + 1);
    w.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    int ans = -0x3f3f3f3f;
    for (int u = 1; u <= n; u++)
        ans = max(ans, f[u]);
    cout << ans << endl;
    return 0;
}