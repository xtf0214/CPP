#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;

int V, E;
vector<int> G[N];
bool vis[N];
vector<int> rG[N], vs;
int color[N];

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u])
        if (!vis[v])
            dfs(v);
    vs.push_back(u);
}
void rdfs(int u, int k) {
    color[u] = k;
    for (int v : rG[u])
        if (!color[v])
            rdfs(v, k);
}
void contract(int scc) {
    vector<set<int>> g(scc + 1);
    vector<vector<int>> ver(scc + 1);
    for (int u = 1; u <= V; u++) {
        ver[color[u]].push_back(u);
        for (int v : G[u]) {
            if (color[u] != color[v]) {
                g[color[u]].insert(color[v]);
            }
        }
    }
    // 缩点DAG
    for (int u = 1; u <= scc; u++) {
        cout << u << "[\"{";
        for (int v : ver[u])
            cout << v << ',';
        cout << "}\"]";
        cout << '\n';
        for (int v : g[u])
            cout << u << "--->" << v << '\n';            
    }
}
int kosaraju() {
    int scc = 0;
    for (int i = 1; i <= V; i++)
        if (!vis[i])
            dfs(i);
    // dfs后序遍历生成表
    for (int i : vs)
        printf("%d--->", i);
    cout << endl << endl;

    reverse(vs.begin(), vs.end());
    for (int i : vs)
        if (!color[i])
            rdfs(i, ++scc);
    // 颜色编号
    for (int i = 1; i <= V; i++)
        printf("%d[%d:%d]\n", i, i, color[i]);
    cout << endl;
    contract(scc);
    return scc;
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    cout << kosaraju() << endl;
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