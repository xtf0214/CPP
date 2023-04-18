// 7-1 旅游规划
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
struct Edge {
    int to, d, w;
};
int V, E, S, D;
vector<Edge> G[N];
bool vis[N];
int dist[N], cost[N];

void dijkstra(int s) {
    memset(dist, INF, sizeof(dist));
    memset(cost, INF, sizeof(cost));
    dist[s] = 0, cost[s] = 0;
    while (true) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || dist[i] < dist[u]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        for (auto &[v, d, w] : G[u])
            if (dist[v] > dist[u] + d) // 松弛操作，优先选择距离近的路线
            {
                dist[v] = dist[u] + d;
                cost[v] = cost[u] + w;
            } else if (dist[v] == dist[u] + d) // 距离相同两种路线，选择花钱少的
                cost[v] = min(cost[v], cost[u] + w);
    }
}
int main() {
    cin >> V >> E >> S >> D;
    for (int i = 0, u, v, d, w; i < E; i++) {
        cin >> u >> v >> d >> w;
        G[u].push_back({v, d, w});
        G[v].push_back({u, d, w});
    }
    dijkstra(S);
    cout << dist[D] << " " << cost[D];
    return 0;
}