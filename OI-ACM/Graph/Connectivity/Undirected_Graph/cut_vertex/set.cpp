#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];

int dfn[MAX_V], low[MAX_V];
int timer = 0;
set<int> cut_vertex;

void tarjan(int u, int fa)
{
    low[u] = dfn[u] = ++timer;
    int child = 0;
    for (int v : adjs[u])
    {
        if (!dfn[v])
        {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa != u && low[v] >= dfn[u])
                cut_vertex.insert(u);
        }
        else if (fa != v)
            low[u] = min(low[u], dfn[v]);
    }
    if (fa == u && child >= 2)
        cut_vertex.insert(u);
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
    for (int i = 1; i <= V; i++)
        if (dfn[i] == 0)
            tarjan(i, i);
    cout << cut_vertex.size() << endl;
    for (int i : cut_vertex)
        cout << i << " ";
    return 0;
}