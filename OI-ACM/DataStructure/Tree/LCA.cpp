/**
 * @file    :   LCA 最近公共祖先
 * @author  :   Tanphoon
 * @date    :   2023/04/26 01:26
 * @version :   2023/04/26 01:26
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 5;

int n;
vector<int> G[N];
int fa[N][20], dep[N], sum[N];

void dfs(int u, int pa) {
    fa[u][0] = pa;
    for (int i = 1; (1 << i) <= dep[u]; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : G[u])
        if (v != pa) {
            dep[u] = dep[pa] + 1;
            sum[u] = sum[v] + 1;
            dfs(v, u);
        }
}
int LCA(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; i >= 0; i--)
        if (dep[x] - (1 << i) >= dep[y])
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = 19; i >= 0; i--)
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    return fa[x][0];
}
int dist(int x, int y) { return sum[x] + sum[y] - 2 * sum[LCA(x, y)]; }
int main() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    return 0;
}