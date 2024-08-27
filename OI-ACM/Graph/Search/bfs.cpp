#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int V, E;
vector<int> G[N];
bool vis[N];

void bfs(int u) {
    queue<int> q;
    vis[u] = true;
    q.push(u);
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (int v : G[u])
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
    }
}
int main() {
    cin >> V >> E;
    fill(vis, vis + V, false);
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
        if (!vis[i])
            bfs(i);
    return 0;
}