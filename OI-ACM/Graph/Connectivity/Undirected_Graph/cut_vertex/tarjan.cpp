#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];

int dfn[MAX_V], low[MAX_V];
int cnt = 0, timer = 0;
bool cut_vertex[MAX_V];

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
            if (fa != u && low[v] >= dfn[u] && !cut_vertex[u])
                cut_vertex[u] = true, cnt++;
        }
        else if (fa != v)
            low[u] = min(low[u], dfn[v]);
    }
    if (fa == u && child >= 2 && !cut_vertex[u])
        cut_vertex[u] = true, cnt++;
}
int main()
{
    // ifstream fin("D:/Code/cpp/OI-ACM/Graph/Connectivity/Undirected_Graph/VE2.in");
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++)
    {
        cin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    for (int i = 1; i <= V; i++)
        if (!dfn[i])
            tarjan(i, i);
    // for (int i = 1; i <= V; i++)
    //     printf("%d[%d:%d_%d]\n", i, i, dfn[i], low[i]);
    cout << cnt << endl;
    for (int i = 1; i <= V; i++)
        if (cut_vertex[i])
            cout << i << " ";
    return 0;
}