#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 0x29292929;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

vector<int> radjs[MAX_V], vs;
int color[MAX_V];

void dfs(int u)
{
    vis[u] = true;
    for (int v : adjs[u])
        if (!vis[v])
            dfs(v);
    vs.push_back(u);
}
void rdfs(int u, int k)
{
    color[u] = k;
    for (int v : radjs[u])
        if (!color[v])
            rdfs(v, k);
}
int kosaraju()
{
    int scc = 0;
    for (int i = 1; i <= V; i++)
        if (!vis[i])
            dfs(i);
    // for (int i : vs)
    //     printf("%d--->", i);
    for (auto it = vs.rbegin(); it != vs.rend(); it++)
        if (!color[*it])
            rdfs(*it, ++scc);
    return scc;
}
int main()
{
    ifstream fin("D:/Code/cpp/OI-ACM/Graph/Connectivity/Driected_Graph/VE.in");
    fin >> V >> E;
    for (int i = 0, u, v; i < E; i++)
    {
        fin >> u >> v;
        adjs[u].push_back(v);
        radjs[v].push_back(u);
    }
    cout << kosaraju() << endl;
    // for (int i = 1; i <= V; i++)
    //     printf("%d[%d:%d]\n", i, i, color[i]);
    return 0;
}