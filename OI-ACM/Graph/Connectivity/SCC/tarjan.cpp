#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int V, E;
vector<int> G[N];

int dfn[N], low[N];
int cnt = 0, timer = 0;
int scc[N], sz[N]; // scc[i]：i所在的强连通分量，sz[i]：强连通分量i包含的节点数
stack<int> s;
bool in_stack[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++timer;
    s.push(u);
    in_stack[u] = true;
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        int v;
        ++cnt;
        do {
            v = s.top(), s.pop();
            in_stack[v] = false;
            scc[v] = cnt;
            sz[cnt]++;
        } while (u != v);
    }
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (int i = 1; i <= V; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= V; i++)
        printf("%d[\"%d,%d,%d,%d\"]\n", i, i, scc[i], dfn[i], low[i]);
    cout << cnt << endl;
    return 0;
}
/*
12 16
2 3
3 2
4 1
4 3
5 7
6 3
6 4
6 5
7 6
8 10
9 7
9 8
10 9
11 8
11 10
12 11 */