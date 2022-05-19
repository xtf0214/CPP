#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to, cost;
};
typedef pair<int, int> Node; //{int dist,id}
const int MAX = 1000, INF = 2 << 14;
int V, E;
vector<Edge> edges[MAX];
int d[MAX];
void dijkstra(int s)
{
    fill(d, d + V + 1, INF);
    priority_queue<Node, vector<Node>, greater<Node>> que;
    d[s] = 0;
    que.push({0, s});
    while (!que.empty())
    {
        Node t = que.top();
        que.pop();
        int u = t.second;
        if (d[u] < t.first)
            continue;
        for (Edge e : edges[u])
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                que.push({d[e.to], e.to});
            }
    }
    // for (int i = 1; i <= V; i++)
    //     printf("d[%d] = %d\n", i, d[i]);
}
int main()
{
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    int sum = 0;
    dijkstra(1);
    for (int i = 1; i <= V; i++)
        sum += d[i];
    for (int i = 2; i <= V; i++)
    {
        dijkstra(i);
        sum += d[1];
    }
    cout << sum;
}