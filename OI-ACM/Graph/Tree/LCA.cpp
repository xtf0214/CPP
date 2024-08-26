/**
 * @file    :   LCA 最近公共祖先
 * @author  :   Tanphoon
 * @date    :   2023/04/26 01:26
 * @version :   2023/04/26 01:26
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 5;

int n;
vector<int> G[N];
int p[N][20], dep[N], sum[N];

void dfs(int u, int fa) {
    p[u][0] = fa;
    dep[u] = dep[fa] + 1;
    sum[u] = sum[fa] + 1;
    for (int i = 1; i <= __lg(dep[u]); i++)
        p[u][i] = p[p[u][i - 1]][i - 1];
    for (int v : G[u])
        if (v != fa) {
            dfs(v, u);
        }
}
int LCA(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = __lg(dep[x] - dep[y]); i >= 0; i--)
        if (dep[p[x][i]] >= dep[y])
            x = p[x][i];
    if (x == y)
        return x;
    for (int i = __lg(dep[x]); i >= 0; i--)
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    return p[x][0];
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