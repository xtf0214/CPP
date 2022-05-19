#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 0x29292929;
int V, E;
struct Edge
{
    int u, v, cost;
};
vector<Edge> edges;

int d[MAX_V], p[MAX_V];

void BellmanFord(int s)
{
    fill(d, d + V, INF);
    fill(p, p + V, -1);
    d[s] = 0;
    while (true)
    {
        bool update = false;
        for (Edge e : edges) //适用于有向图
            if (d[e.v] > d[e.u] + e.cost)
            {
                d[e.v] = d[e.u] + e.cost, p[e.v] = e.u;
                update = true;
            }
        if (!update)
            break;
    }
    for (int i = 0; i < V; i++)
    {
        printf("d[%d] = %d\n", i, d[i]);
        for (int u = i; u != -1; u = p[u])
            u == i ? printf("%d", u) : printf(" -> %d", u);
        printf("\n");
    }
}
int main()
{
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    BellmanFord(0);
    return 0;
}