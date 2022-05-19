#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 0x29292929;
int V;
int cost[MAX_V][MAX_V];

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
        for (int v = 0; v < V; v++)
            d[v] = min(d[v], cost[u][v] + d[u]);
    }
}
int main()
{
    cin >> V;
    for (int i = 0; i < V; i++)
        for (int j = 0, e; j < V; j++)
            (cin >> e), cost[i][j] = e == -1 ? INF : e;
    Dijkstra(0);
    for (int i = 0; i < V; i++)
        printf("%d: %d\n", i, d[i]);
    return 0;
}