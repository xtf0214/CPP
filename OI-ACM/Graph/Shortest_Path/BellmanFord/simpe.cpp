#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;

int V, E;
struct Edge {
    int u, v, w;
};
vector<Edge> edges;

int d[N], p[N];

void BellmanFord(int s) {
    fill(d, d + V, INF);
    fill(p, p + V, -1);
    d[s] = 0;
    while (true) {
        bool update = false;
        for (auto [u, v, w] : edges) // 适用于有向图
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w, p[v] = u;
                update = true;
            }
        if (!update)
            break;
    }
    for (int i = 0; i < V; i++) {
        printf("d[%d] = %d\n", i, d[i]);
        for (int u = i; u != -1; u = p[u])
            u == i ? printf("%d", u) : printf(" -> %d", u);
        printf("\n");
    }
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    BellmanFord(0);
    return 0;
}
/* 
7 12
0 1 10
0 2 3 
0 4 18
0 5 11
1 2 5
1 3 1
2 3 2
2 5 7
2 6 5
3 6 2
4 5 1
5 6 2 */