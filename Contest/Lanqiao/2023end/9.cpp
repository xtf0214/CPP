#include <bits/stdc++.h>
using namespace std;

#ifdef _LQDEBUG
#define db(x) cout << #x << " = " << x << endl
#define cin fin
fstream fin("C:\\Users\\Administrator\\Desktop\\input\\9.txt");
#endif

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e4 + 5;

int n, k;
vector<pii> G[N];
ll d[N][N];
ll dist[N];
int path[N];
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
    for (int i = 1; i <= k; i++) {
        cin >> path[i];
    }
    for (int i = 1; i <= k; i++) {
        ll ans = 0;
        vector<int> way;
        for (int j = 1; j <= k; j++)
            if (j != i)
                way.push_back(path[j]);
        for (int j = 1; j < way.size(); j++)
            ans += d[way[j - 1]][way[j]];
        cout << ans << " ";
    }
    return 0;
}
