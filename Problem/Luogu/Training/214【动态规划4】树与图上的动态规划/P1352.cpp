/**
 * @file    :   P1352 没有上司的舞会
 * @author  :   Tanphoon
 * @date    :   2023/02/26 02:41
 * @version :   2023/02/26 02:41
 * @link    :   https://www.luogu.com.cn/problem/P1352
 */
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> G, f;
vector<int> a;

void dfs(int u, int fa) {
    f[u][0] = 0;
    f[u][1] = a[u];
    for (int v : G[u])
        if (v != fa) {
            dfs(v, u);
            f[u][0] += max(f[v][0], f[v][1]);
            f[u][1] += f[v][0];
        }
}
int main() {
    cin >> n;
    a.resize(n + 1);
    f.resize(n + 1, vector<int>(2));
    G.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(f[1][0], f[1][1]);
    return 0;
}