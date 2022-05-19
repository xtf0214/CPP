#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 20;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

queue<int> q;

void bfs(int u)
{
    vis[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adjs[u])
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
    }
}
int main()
{
    ifstream fin("VE.in");
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
            bfs(i);
    return 0;
}