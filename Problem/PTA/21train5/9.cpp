#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> G;
vector<int> path;
bool hamilton() {
    if (path.size() != V + 1 || path.front() != path.back())
        return false;
    vector<bool> vis(V + 1, false);
    for (int i = 1; i < path.size(); i++) {
        int u = path[i - 1], v = path[i];
        if (!G[u][v] || vis[v])
            return false;
        vis[v] = true;
    }
    return true;
}
signed main() {
    cin >> V >> E;
    G.resize(V + 1, vector<int>(V + 1));
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    int k, n;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        path.resize(n);
        for (int i = 0; i < n; i++)
            cin >> path[i];
        puts(hamilton() ? "YES" : "NO");
    }
    return 0;
}