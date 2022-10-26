#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v, cost;
    bool operator<(const Edge &t) { return cost < t.cost; }
};
vector<Edge> edges;
int V, E;
class DisjointSet
{
private:
    vector<int> rank, p;

public:
    DisjointSet(int n)
    {
        rank.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++)
            rank[i] = 0, p[i] = i;
    }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        rank[x] < rank[y] ? p[x] = y : p[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
};
int kruskal()
{
    int sum = 0, cnt = 0;
    bool vis[V + 1];
    DisjointSet dset(V + 1);
    sort(edges.begin(), edges.end());
    for (Edge e : edges)
        if (!dset.same(e.u, e.v))
        {
            sum += e.cost;
            dset.unite(e.u, e.v);
            vis[e.u] = vis[e.v] = true;
            cnt++;
        }
    // for (int i = 1; i <= V; i++)
    //     if (!vis[i])
    //         return -1;
    if (cnt < V - 1)
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
    cout << kruskal();
    return 0;
}