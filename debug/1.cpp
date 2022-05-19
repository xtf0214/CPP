#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10, M = 200000 + 10;
int n, m, s, t;
struct edge
{
    int v, w, nxt;
} e[M];
int head[N];
void addEdge(int u, int v, int w)
{
    static int cnt = 0;
    e[++cnt] = (edge){v, w, head[u]}, head[u] = cnt;
}
typedef pair<int, int> Node;
priority_queue<Node, vector<Node>, greater<Node>> Q;
int d[N];
void dijkstra(int s)
{
    memset(d, 0x3f3f, sizeof(d));
    d[s] = 0, Q.push({0, s});
    while (!Q.empty())
    {
        Node p = Q.top();
        Q.pop();
        int u = p.second;
        if (d[u] < p.first)
            continue;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v, w = e[i].w;
            if (d[u] + w < d[v])
                d[v] = d[u] + w, Q.push(make_pair(d[v], v));
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; ++i)
        printf("%d%c", d[i], " \n"[i == n]);
    return 0;
}