#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int N = 500 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct Node {
    int to, len, time;
};
int n, m, src, dst;
vector<Node> G[N];
bool vis[N];
int dist[N], cost[N];

void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(cost, 0x3f, sizeof(cost));
    dist[s] = 0;
    cost[s] = 0;
    while (true) {}
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, directed, len, time;
        cin >> u >> v >> directed >> len >> time;
        G[u].push_back({v, len, time});
        if (!directed)
            G[v].push_back({u, len, time});
    }
    cin >> src >> dst;
    dijkstra(src);
}