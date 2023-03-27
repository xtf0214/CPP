#include <bits/stdc++.h>
using namespace std;
using Node = pair<int, int>;
const int N = 100 + 5;

int n, m;
vector<Node> G[N];
int indeg[N], oudeg[N], dist[N]; // 入度，出度，路径长度
vector<int> path;                // 记录路径

bool tsort() {
    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            Q.push(i);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        path.push_back(u);
        for (auto &[v, w] : G[u]) {
            if (--indeg[v] == 0)
                Q.push(v);
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    return path.size() == n;
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        indeg[v]++;
        G[u].push_back({v, w});
    }
    if (tsort()) {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (oudeg[i] == 0)
                ans = max(ans, dist[i]);
        cout << ans;
    } else {
        puts("Impossible");
    }
}