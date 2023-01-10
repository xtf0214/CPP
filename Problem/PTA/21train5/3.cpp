#include <bits/stdc++.h>
using namespace std;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << "  "[++i == v.size()])

int V, E;
vector<vector<int>> G;
vector<int> vis, path;
void dfs(int u) {
    path.push_back(u);
    vis[u] = true;
    for (int v = 0; v < V; v++)
        if (G[u][v] && !vis[v])
            dfs(v);
}
void bfs(int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front(), q.pop();
        path.push_back(u);
        vis[u] = true;
        for (int v = 0; v < V; v++)
            if (G[u][v] && !vis[v]) {
                q.push(v);
                vis[v] = true;
            }
    }
}
signed main() {
    cin >> V >> E;
    G.assign(V, vector<int>(V));
    vis.assign(V, 0);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    for (int u = 0; u < V; u++) 
        if (!vis[u]) {
            dfs(u);
            cout << "{ ";
            print(path);
            cout << "}" << endl;
            path.clear();
        }
    vis.assign(V, 0);
    for (int u = 0; u < V; u++)
        if (!vis[u]) {
            bfs(u);
            cout << "{ ";
            print(path);
            cout << "}" << endl;
            path.clear();
        }
    return 0;
}