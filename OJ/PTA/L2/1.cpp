#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 10000 + 5, INF = 0x3f3f3f3f;
struct Edge
{
    int to, _dist, _cost;
};
int V, E, S, D;
vector<Edge> adjs[MAX_V];

bool vis[MAX_V];
int dist[MAX_V], cost[MAX_V];
void dijkstra(int s)
{
    memset(dist, INF, sizeof(dist));
    memset(cost, INF, sizeof(cost));
    dist[s] = 0, cost[s] = 0;
    while (true)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || dist[i] < dist[u]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        for (Edge e : adjs[u])
            if (dist[u] + e._dist < dist[e.to]) // 松弛操作，优先选择距离近的路线
            {
                dist[e.to] = dist[u] + e._dist;
                cost[e.to] = cost[u] + e._cost;
            } 
            else if (dist[u] + e._dist == dist[e.to]) //距离相同两种路线，选择花钱少的
                cost[e.to] = min(cost[e.to], cost[u] + e._cost);
    }
}
int main()
{
    cin >> V >> E >> S >> D;
    for (int i = 0, u, v, d, w; i < E; i++)
    {
        cin >> u >> v >> d >> w;
        adjs[u].push_back({v, d, w});
        adjs[v].push_back({u, d, w});
    }
    dijkstra(S);
    cout << dist[D] << " " << cost[D];
    return 0;
}