#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100;
int V, E;
vector<int> adjs[MAX_V];

int p[MAX_V];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int cc()
{
    int res = 0;
    for (int i = 0; i < V; i++)
        p[i] = i;
    for (int u = 0; u < V; u++)
        for (int v : adjs[u])
            if (find(u) != find(v))
                p[u] = v;
    for (int i = 0; i < V; i++)
        if (find(i) == i)
            res++;
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