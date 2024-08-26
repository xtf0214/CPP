#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;

int V, E;
vector<pair<int, int>> G[N];
int d[N];
bool vis[N];

int Prim() {
    int sum = 0;
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[0] = 0;
    while (true) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || d[i] < d[u]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        sum += d[u];
        for (auto [v, w] : G[u])
            d[v] = min(d[v], w);
    }
    return sum;
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    cout << Prim();
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