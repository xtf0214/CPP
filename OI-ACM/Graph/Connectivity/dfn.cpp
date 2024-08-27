#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int V, E;
vector<int> G[N];
bool vis[N];
int pre[N], post[N], timer = 0;

void dfs(int u) {
    vis[u] = true;
    pre[u] = ++timer;
    for (int v : G[u])
        if (!vis[v])
            dfs(v);
    post[u] = ++timer;
}
int main() {
    cin >> V >> E;
    fill(vis, vis + V, false);
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i);
    for (int i = 0; i < V; i++)
        printf("%d[\"%d,%d,%d\"]\n", i, i, pre[i], post[i]);
    return 0;
}
/* 
8 10
0 1
0 2
0 3
1 2
2 3
3 4
3 5
5 6
5 7
6 7 */