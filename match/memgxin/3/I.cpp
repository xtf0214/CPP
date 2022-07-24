#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1e5 + 5, INF = 0x3f3f3f3f;
int V, E, x;
struct Edge
{
    int to, cost;
};
vector<Edge> adjs[MAX_V];

typedef pair<int, int> Node; // Node(int dist, int id)
int d[MAX_V], pre[MAX_V];

void dijkstra(int s)
{
    priority_queue<Node, vector<Node>, greater<Node>> que; //默认对pair.first排序
    fill(d, d + V, INF);
    d[s] = 0, pre[s] = -1;
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
                que.push({d[e.to] = d[u] + e.cost, e.to}), pre[e.to] = u;
    }
}
int main()
{
    cin >> V >> E >> x;
    // cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        u--, v--;
        adjs[u].push_back({v, w});
    }
    dijkstra(0);
    int res = 0;
    for (int i = 0; i < V;i++)
        cout << d[i] << " ";
    cout << endl;
    for (int u = V - 1; u != 0; u = pre[u])
        res++;
    cout << d[V - 1] + res;
    return 0;
}