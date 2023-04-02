#include <bits/stdc++.h>
using namespace std;
using Edge = pair<int, int>;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

vector<Edge> G[N];
int dist[N];
bool vis[N];
int n, m, k;

void dijkstra(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    int maxdist = 0, idx = 0;
    while (true) {
        int u = -1, minv = INF;
        for (int i = 1; i <= n; i++)
            if (minv > dist[i] && !vis[i])
                u = i, minv = dist[i];
        if (u == -1)
            break;
        vis[u] = true;
        for (auto &[v, w] : G[u])
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (maxdist < dist[v]) {
                    maxdist = dist[v];
                    idx = v;
                } else if (maxdist == dist[v])
                    idx = min(idx, v);
            }
    }
    cout << idx << endl;
}
int main() {
    cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back({b, 1});
        G[b].push_back({a, 1});
    }
    for (int i = 0, t; i < k; i++) {
        cin >> t;
        dijkstra(t);
    }
    return 0;
}