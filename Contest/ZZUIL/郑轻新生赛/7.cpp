#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to, cost, used;
};
struct ed
{
    int u, v;
};
typedef pair<int, int> P;
const int MAX_V = 124755, INF = 0x3f3f3f3f;
int V, E;
vector<Edge> G[MAX_V];
vector<ed> Graph;
int d[MAX_V];
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V + 1, INF);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (Edge e : G[v])
        {
            if (e.used == true)
                continue;
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}
int main()
{
    int s, n;
    cin >> V >> E >> s;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        Graph.push_back({u, v});
        G[u].push_back({v, w, 0});
        G[v].push_back({u, w, 0});
    }
    for (int i = 0; i < s; i++)
    {
        cin >> n;
        vector<int> a;
        for (int i = 0, k; i < n; i++)
        {
            cin >> k;
            a.push_back(k);
            int u = Graph[k - 1].u, v = Graph[k - 1].v;
            for (int i = 0; i < G[u].size(); i++)
                if (G[u][i].to == v)
                {
                    G[u][i].used = true;
                    break;
                }
            for (int i = 0; i < G[v].size(); i++)
                if (G[v][i].to == u)
                {
                    G[v][i].used = true;
                    break;
                }
        }
        dijkstra(1);
        cout << d[V] << endl;
        for (int i = 0; i < n; i++)
        {
            int k = a[i];
            int u = Graph[k - 1].u, v = Graph[k - 1].v;
            for (Edge e : G[v])
                if (e.to == v)
                {
                    G[u][i].used = false;
                    break;
                }
            for (int i = 0; i < G[v].size(); i++)
                if (G[v][i].to == u)
                {
                    G[v][i].used = false;
                    break;
                }
        }
    }
}