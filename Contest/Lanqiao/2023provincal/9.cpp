#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 5;

int n, k;
vector<pii> G[N];
ll dist[N];
void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});

    while (!q.empty()) {
        int dist_u = q.top().first, u = q.top().second;
        q.pop();
        if (dist_u > dist[u])
            continue;
        for (auto &e : G[u]) {
            int v = e.first, w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}
int main() {
    cin >> n >> k;
    vector<vector<ll>> d(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for (int s = 1; s <= n; s++) {
        dijkstra(s);
        for (int t = 1; t <= n; t++)
            d[s][t] = dist[t];
    }
    vector<int> q(k + 2);
    for (int i = 1; i <= k; i++)
        cin >> q[i];
    ll ans = 0;
    for (int i = 1; i <= k; i++)
        ans += d[q[i - 1]][q[i]];
    for (int i = 1; i <= k; i++) {
        int l = i - 1, r = i + 1;
        cout << ans - d[q[l]][q[i]] - d[q[i]][q[r]] + d[q[l]][q[r]] << " ";
    }
    return 0;
}
