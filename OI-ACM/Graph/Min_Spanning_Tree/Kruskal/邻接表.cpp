#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 0x29292929;
int V, E;
struct Edge
{
    int u, v, cost;
    bool operator<(const Edge &e) const { return cost < e.cost; }
};
vector<Edge> edges;

int p[MAX_V];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int kruskal()
{
    int sum = 0;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < V; i++)
        p[i] = i;
    for (Edge e : edges)
        if (find(e.u) != find(e.v))
        {
            sum += e.cost;
            p[e.u] = e.v;
        }
    return sum;
}
int main()
{
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    cout << kruskal() << endl;
    return 0;
}