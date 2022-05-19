#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

int pre[MAX_V], post[MAX_V], timer = 0;

void dfs(int u)
{
    vis[u] = true;
    pre[u] = ++timer;
    printf("%d: %d\n", u, timer);
    for (int v : adjs[u])
        if (!vis[v])
            dfs(v);
    post[u] = ++timer;
    printf("%d: %d\n", u, timer);
}
int main()
{
    #define cin fin
    ifstream fin("D:/Code/cpp/OI-ACM/Graph/Connectivity/Undirected_Graph/VE.in");
    cin >> V >> E;
    fill(vis, vis + V, false);
    for (int i = 0, u, v; i < E; i++)
    {
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i);
    return 0;
}