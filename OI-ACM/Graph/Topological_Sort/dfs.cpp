#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

list<int> ans;

void dfs(int u)
{
    vis[u] = true;
    for (int v : adjs[u])
        if (!vis[v])
            dfs(v);
    ans.push_front(u);
}
void tsort()
{
    fill(vis, vis + V, false);
    for (int s = 0; s < V; s++)
        if (!vis[s])
            dfs(s);
}
int main()
{
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++)
    {
        cin >> u >> v;
        adjs[u].push_back(v);
    }
    tsort();
    for (int i : ans)
        cout << i << endl;
    return 0;
}