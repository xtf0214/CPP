#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
vector<int> G[N];
int vis[N];
int n, m, cnt;

void dfs(int u, int t) {
    if (vis[u])
        return;
    vis[u] = t;
    cout << u << " ";
    for (int v : G[u])
        dfs(v, t);
}
void bfs(int u, int t) {
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = t;
        cout << u << " ";
        for (int v : G[u])
            Q.push(v);
    }
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int u = 0; u < n; u++)
        sort(G[u].begin(), G[u].end());

    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            cout << "{ ";
            dfs(u, ++cnt);
            cout << "}\n";
        }
    }
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int u = 0; u < n; u++)
        if (!vis[u]) {
            cout << "{ ";
            bfs(u, ++cnt);
            cout << "}\n";
        }
}