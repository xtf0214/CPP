#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int V, E;
vector<int> G[N];

int dfn[N], low[N];
int cnt = 0, timer = 0;
bool cut_edge[N];
int father[N];

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++timer;
    father[u] = fa;
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u] && !cut_edge[u])
                cut_edge[v] = true, cnt++;
        } else if (fa != v)
            low[u] = min(low[u], dfn[v]);
    }
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
        if (!dfn[i])
            tarjan(i, i);
    for (int i = 0; i < V; i++)
        printf("%d[\"%d,%d,%d\"]\n", i, i, dfn[i], low[i]);
    cout << cnt << endl;
    for (int i = 0; i < V; i++)
        if (cut_edge[i])
            cout << father[i] << "-" << i << endl;
    return 0;
}
/*
8 10
0 1
0 2
0 3
1 2
2 3
3 4
3 5
5 6
5 7
6 7 */