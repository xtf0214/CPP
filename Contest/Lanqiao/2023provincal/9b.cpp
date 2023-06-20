/**
 * @file    :   9 景区导游
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

int n, k;
vector<pii> G[N];
int fa[N][20], dep[N];
ll sum[N];

void dfs(int u, int pa) {
    fa[u][0] = pa;
    for (int i = 1; (1 << i) <= dep[u]; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto &e : G[u]) {
        int v = e.first, w = e.second;
        if (v != pa) {
            dep[v] = dep[u] + 1;
            sum[v] = sum[u] + w;
            dfs(v, u);
        }
    }
}
int LCA(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; i >= 0; i--)
        if (dep[fa[x][i]] >= dep[y])
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
ll dist(int x, int y) { return sum[x] + sum[y] - 2 * sum[LCA(x, y)]; }
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dep[1] = 1;
    dfs(1, 0);
    vector<int> q(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> q[i];
    ll res = 0;
    for (int i = 2; i <= k; i++)
        res += dist(q[i - 1], q[i]);
    for (int i = 1; i <= k; i++) {
        ll ans = res;
        if (1 <= i - 1)
            ans -= dist(q[i - 1], q[i]);
        if (i + 1 <= k)
            ans -= dist(q[i], q[i + 1]);
        if (1 <= i - 1 && i + 1 <= k)
            ans += dist(q[i - 1], q[i + 1]);
        cout << ans << " ";
    }
    return 0;
}