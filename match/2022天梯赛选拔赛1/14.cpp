#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V = 1000, INF = 0x29292929;
struct Node
{
    int d = INF;
    bool used = false;
};
struct Dot
{
    int id, dis;
    Dot(int id, int dis) : id(id), dis(dis) {}
};
int n, m, k;
struct Edge
{
    int v, dis;
    Edge(int v, int dis) : v(v), dis(dis) {}
};
vector<Edge> cost[MAX_V];
bool cmp(const Dot &a, const Dot &b)
{
    if (a.dis != b.dis)
        return a.dis > b.dis;
    else
        return a.id < b.id;
}
void Dijkstra(int x)
{
    Node nodes[n + 1];
    nodes[x].d = 0;
    while (true)
    {
        int u = -1, minv = INF;
        for (int i = 1; i <= n; i++)
            if (minv > nodes[i].d && !nodes[i].used)
                u = i, minv = nodes[i].d;
        if (u == -1 || minv == INF)
            break;
        nodes[u].used = true;
        for (int i = 0; i < cost[u].size(); i++)
        {
            Edge e = cost[u][i];
            if (!nodes[e.v].used)
                if (e.dis + nodes[u].d < nodes[e.v].d)
                    nodes[e.v].d = e.dis + nodes[u].d;
        }
    }
    vector<Dot> S;
    for (int i = 1; i <= n; i++)
        if (nodes[i].d != INF)
            S.push_back(Dot(i, nodes[i].d));
    sort(S.begin(), S.end(), cmp);
    Dot k = S[0];
    if (k.id == x)
        cout << 0 << endl;
    else
        cout << k.id << endl;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        cost[a].push_back({b, 1});
        cost[b].push_back({a, 1});
    }
    for (int i = 0, t; i < k; i++)
    {
        cin >> t;
        Dijkstra(t);
    }
    return 0;
}
