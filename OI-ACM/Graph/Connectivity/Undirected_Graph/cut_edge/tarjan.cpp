#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];

int dfn[MAX_V], low[MAX_V];
int cnt = 0, timer = 0;
bool cut_edge[MAX_V];
int father[MAX_V];

void tarjan(int u, int fa)
{
    low[u] = dfn[u] = ++timer;
    father[u] = fa;
    for (int v : adjs[u])
    {
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u] && !cut_edge[u])
                cut_edge[v] = true, cnt++;
        }
        else if (fa != v)
            low[u] = min(low[u], dfn[v]);
    }
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
        if (cut_edge[i])
            cout << father[i] << "-" << i << endl;
    return 0;
}