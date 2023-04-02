#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

vector<int> G[N];
int dist[N];
bool vis[N];
int n, m, k;

void bfs(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    int maxdist = 0, idx = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u])
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
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
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0, t; i < k; i++) {
        cin >> t;
        bfs(t);
    }
    return 0;
}