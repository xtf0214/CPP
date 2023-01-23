#include <bits/stdc++.h>
using namespace std;
using Node = pair<int, int>;
const int INF = 0x3f3f3f3f;

int V, E;
vector<vector<Node>> G;
vector<int> dist;
vector<bool> vis;

void dijkstra(int s) {
    dist.assign(V, INF);
    vis.assign(V, false);
    dist[s] = 0;
    while (true) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || dist[u] > dist[i]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        for (auto &[v, w] : G[u])
            dist[v] = min(dist[v], dist[u] + w);
    }
}
void dijkstra_heap(int s) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    dist.assign(V, INF);
    vis.assign(V, false);
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto [dist_u, u] = q.top();
        q.pop();
        if (dist[u] < dist_u)
            continue;
        for (auto &[v, w] : G[u])
            if (dist[v] > dist[u] + w)
                q.push({dist[v] = dist[u] + w, v});
    }
}