#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int V, E;
vector<int> G[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u])
        if (!vis[v]) {
            printf("%d--->%d\n", u, v); // 树边
            dfs(v);
        } else if (u < v)
            printf("%d-.->%d\n", v, u); // 背向边
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(vis, vis + V, false);
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i);
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