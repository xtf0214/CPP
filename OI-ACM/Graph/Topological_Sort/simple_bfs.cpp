#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 0x3f3f3f3f;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

vector<int> ans;
int indeg[MAX_V];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : adjs[u])
            if (--indeg[v] == 0 && !vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
    }
}
void tsort()
{
    fill(indeg, indeg + V, 0);
    fill(vis, vis + V, false);
    for (int u = 0; u < V; u++)
        for (int v : adjs[u])
            indeg[v]++;
    for (int u = 0; u < V; u++)
        if (indeg[u] == 0 && !vis[u])
            bfs(u);
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