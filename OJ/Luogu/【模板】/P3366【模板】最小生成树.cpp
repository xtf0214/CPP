#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 5000 + 5, INF = 0x29292929;
int V, E;
struct Edge
{
    int u, v, cost;
    bool operator<(const Edge &e) { return cost < e.cost; }
};
vector<Edge> edges;

int p[MAX_V];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int kruskal()
{
    int sum = 0, cnt = 0;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < V + 1; i++)
        p[i] = i;
    for (Edge e : edges)
        if (find(e.u) != find(e.v))
        {
            sum += e.cost;
            cnt++;
            p[e.u] = e.v;
        }
    if (cnt < V)
        return -1;
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
    int res = kruskal();
    res == -1 ? (cout << "orz" << endl) : (cout << res << endl);
    return 0;
}