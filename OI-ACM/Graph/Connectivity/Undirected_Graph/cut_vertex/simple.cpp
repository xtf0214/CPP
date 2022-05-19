#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

int dfn[MAX_V], low[MAX_V], par[MAX_V];
int cnt = 0, timer = 0;
bool cut_vertex[MAX_V]; // 不考虑树根的点割集

void tarjan(int u, int fa)
{
    low[u] = dfn[u] = ++timer;
    for (int v : adjs[u])
    {
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa != u && low[v] >= dfn[u] && !cut_vertex[u])
                cut_vertex[u] = true, cnt++;
        }
        else if (fa != v)
            low[u] = min(low[u], dfn[v]);
    }
}
int main()
{
    ifstream fin("D:/Code/cpp/OI-ACM/Graph/Connectivity/Undirected_Graph/VE.in");
    fin >> V >> E;
    for (int i = 0, u, v; i < E; i++)
    {
        fin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    // assignDfn(0);
    // assignLow(0);
    tarjan(0, 0);
    cout << cnt << endl;
    for (int i = 0; i < V; i++)
        if (cut_vertex[i])
            cout << i << " ";
    return 0;
}
void assignDfn(int u)
{
    vis[u] = true;
    dfn[u] = ++timer;
    for (int v : adjs[u])
        if (!vis[v])
        {
            par[v] = u;
            assignDfn(v);
        }
}
void assignLow(int u)
{
    low[u] = dfn[u];
    for (int v : adjs[u])
    {
        if (dfn[u] < dfn[v])
        {
            assignLow(v);
            if (u != 0 && dfn[u] <= low[v] && !cut_vertex[u])
                cut_vertex[u] = true, cnt++;
            low[u] = min(low[u], low[v]);
        }
        else if (par[u] != v)
            low[u] = min(low[u], dfn[v]);
    }
}