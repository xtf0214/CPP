#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int V, E;
vector<int> G[N];
int color[N];

void dfs(int u, int k) {
    color[u] = k;
    for (int v : G[u])
        if (!color[v])
            dfs(v, k);
}
int cc() {
    int res = 0;
    for (int i = 0; i < V; i++)
        if (!color[i])
            dfs(i, ++res);
    return res;
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << cc();
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