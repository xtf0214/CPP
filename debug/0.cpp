#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100000 + 5, INF = 0x29292929;
int V, E;
struct Edge
{
    int to, cost;
};
vector<Edge> adjs[MAX_V];

typedef pair<int, int> Node; // Node(int dist, int id)
int d[MAX_V];

void dijkstra(int s)
{
    priority_queue<Node, vector<Node>, greater<Node>> que; //默认对pair.first排序
    fill(d, d + V + 1, INF);
        d[s] = 0;
    que.push({0, s});
    while (!que.empty())
    {
        Node p = que.top();
        que.pop();
        int u = p.second;
        if (d[u] < p.first)
            continue;
        for (Edge e : adjs[u])
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                que.push({d[e.to], e.to});
            }
    }
}
int main()
{
    int s;
    cin >> V >> E >> s;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        adjs[u].push_back({v, w});
    }
    dijkstra(s);
    for (int i = 1; i <= V; i++)
        printf("%d ", d[i]);
    return 0;
}