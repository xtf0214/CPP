#include "bits/stdc++.h"

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> dep(n + 1, 1);
    vector<vector<int>> p(n + 1, vector<int>(__lg(n + 1) + 1));
    vector<i64> sum(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        p[u][0] = fa;
        for (int i = 1; i <= __lg(dep[u]); i++)
            p[u][i] = p[p[u][i - 1]][i - 1];
        for (auto &e : g[u]) {
            int v = e.first, w = e.second;
            if (v != fa) {
                dep[v] = dep[u] + 1;
                sum[v] = sum[u] + w;
                dfs(v, u);
            }
        }
    };

    dfs(1, 0);
    
    auto lca = [&](int x, int y) {
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
    };

    auto dist = [&](int x, int y) {
        int LCA = lca(x, y);
        return sum[x] + sum[y] - 2 * sum[LCA];
    };

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<i64> b(m);
    i64 tot = 0;
    vector<i64> d(m - 1);
    for (int i = 0; i < m - 1; i++) {
        d[i] = dist(a[i], a[i + 1]);
        tot += d[i];
    }

    for (int i = 0; i < m; i++) {
        if (i > 0) {
            b[i] += d[i - 1];
        }
        if (i < m - 1) {
            b[i] += d[i];
        }
        if (i > 0 && i < m - 1) {
            b[i] -= dist(a[i - 1], a[i + 1]);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << tot - b[i] << " \n"[i == m - 1];
    }

    return 0;
}