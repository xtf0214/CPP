#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 2<<21;
int V, E;
vector<pair<int, int>> adjs[MAX_V]; //{int to, cost;}

int d[MAX_V];
bool vis[MAX_V];

void Dijkstra(int s)
{
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[s] = 0;
    while (true)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || d[i] < d[u]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        for (auto e : adjs[u])
            d[e.first] = min(d[e.first], e.second + d[u]);
    }
}
int main()
{
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        adjs[u].push_back({v, w});
        adjs[v].push_back({u, w});
    }
    Dijkstra(0);
    for (int i = 0; i < V; i++)
        printf("%d: %d\n", i, d[i]);
    return 0;
}