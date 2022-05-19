#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];

int color[MAX_V];

void dfs(int u, int k)
{
    color[u] = k;
    for (int v : adjs[u])
        if (!color[v])
            dfs(v, k);
}
int cc()
{
    int res = 0;
    for (int i = 0; i < V; i++)
        if (!color[i])
            dfs(i, ++res);
    return res;
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
    cout << cc();
}