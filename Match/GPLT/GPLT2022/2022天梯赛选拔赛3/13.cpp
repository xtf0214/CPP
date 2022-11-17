// 7-13 公路村村通
#include <iostream>
#include <vector>
using namespace std;
const int MAX_V = 1005, MAX_E = 3005, INF = (1 << 30);
int V, E;
vector<pair<int, int>> edges[MAX_V];
int d[MAX_V];
bool used[MAX_V];
int Prim()
{
    int sum = 0;
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[0] = 0;
    while (true)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || d[i] < d[u]) && !used[i])
                u = i;
        if (u == -1)
            break;
        if (d[u] == INF)
            return -1;
        used[u] = true;
        sum += d[u];
        for (auto e : edges[u])
            d[e.first] = min(d[e.first], e.second);
    }
    return sum;
}
int main()
{
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    cout << Prim();
    return 0;
}