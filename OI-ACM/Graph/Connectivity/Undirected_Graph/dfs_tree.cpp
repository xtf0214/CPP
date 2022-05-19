#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 20;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

void dfs(int u)
{
    vis[u] = true;
    for (int v : adjs[u])
        if (!vis[v])
        {
            printf("%d--->%d\n", u, v); // 树边
            dfs(v);
        }
        else if (u < v)
            printf("%d-.->%d\n", v, u); // 背向边
}
int main()
{
     ifstream fin("D:/Code/cpp/OI-ACM/Graph/Connectivity/Undirected_Graph/VE.in");
    fin >> V >> E;
    fill(vis, vis + V, false);
    for (int i = 0, u, v; i < E; i++)
    {
        fin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i);
    return 0;
}
