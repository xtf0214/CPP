#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int V, E;
vector<int> G[N];
bool vis[N];
vector<int> ans;

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u])
        if (!vis[v])
            dfs(v);
    ans.push_back(u);
}
void tsort() {
    fill(vis, vis + V, false);
    for (int s = 0; s < V; s++)
        if (!vis[s])
            dfs(s);
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
    }
    tsort();
    for (int i : ans)
        cout << i << endl;
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