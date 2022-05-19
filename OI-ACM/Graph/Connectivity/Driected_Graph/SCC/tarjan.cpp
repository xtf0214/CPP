#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];

int dfn[MAX_V], low[MAX_V];
int cnt = 0, timer = 0;
int scc[MAX_V], sz[MAX_V]; // scc[i]：i所在的强连通分量，sz[i]：强连通分量i包含的节点数
stack<int> s;
bool in_stack[MAX_V];

void tarjan(int u)
{
    low[u] = dfn[u] = ++timer;
    s.push(u);
    in_stack[u] = true;
    for (int v : adjs[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        int v;
        do
        {
            v = s.top();
            s.pop();
            scc[v] = cnt;
            sz[cnt]++;
            in_stack[v] = false;
        } while (u != v);
    }
}
int main()
{
    ifstream fin("D:/Code/cpp/OI-ACM/Graph/Connectivity/Driected_Graph/VE.in");
    fin >> V >> E;
    for (int i = 0, u, v; i < E; i++)
    {
        fin >> u >> v;
        adjs[u].push_back(v);
    }
    for (int i = 1; i <= V; i++)
        if (!dfn[i])
            tarjan(i);
    // for (int i = 1; i <= V; i++)
    //     printf("%d[%d:%d_%d]\n", i, i, dfn[i], low[i]);
    // cout << cnt << endl;
    // for (int i = 1; i <= V; i++)
    //     if (cut_vertex[i])
    //         cout << i << " ";
    return 0;
}
