#include <bits/stdc++.h>
using namespace std;
const int N = 20;

int V, E;
vector<int> adjs[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for (int v : adjs[u])
        if (!vis[v])
            dfs(v);
}
int main() {
    cin >> V >> E;
    fill(vis, vis + V, false);
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i);
    return 0;
}
/* 
7 11
0 1
0 2
0 4
1 2
1 3
2 3
2 4
2 5
2 6
3 6
5 6 */