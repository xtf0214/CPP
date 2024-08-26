#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 1e9;
using Node = pair<int, int>;
int V, E;
vector<Node> G[N];
int d[N];
bool vis[N];

void dijkstra(int s) {
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[s] = 0;
    while (true) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || d[u] > d[i]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        for (auto &[v, w] : G[u])
            d[v] = min(d[v], d[u] + w);
    }
}
void dijkstra_heap(int s) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto [d_u, u] = q.top();
        q.pop();
        if (d[u] < d_u)
            continue;
        for (auto &[v, w] : G[u])
            if (d[v] > d[u] + w)
                q.push({d[v] = d[u] + w, v});
    }
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(0);
    for (int i = 0; i < V; i++)
        printf("%d: %d\n", i, d[i]);

    dijkstra_heap(0);
    for (int i = 0; i < V; i++)
        printf("%d: %d\n", i, d[i]);

    return 0;
}
/* 
7 12
0 1 10
0 2 3 
0 4 18
0 5 11
1 2 5
1 3 1
2 3 2
2 5 7
2 6 5
3 6 2
4 5 1
5 6 2 */