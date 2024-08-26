#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;
int V, E;
vector<int> G[N];
vector<int> ans;
int indeg[N];

void tsort() {
    queue<int> q;
    fill(indeg, indeg + V, 0);
    for (int u = 0; u < V; u++)
        for (int v : G[u])
            indeg[v]++;
    for (int u = 0; u < V; u++)
        if (indeg[u] == 0)
            q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : G[u])
            if (--indeg[v] == 0)
                q.push(v);
    }
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
    }
    tsort();
    for (int i : ans)
        cout << i << endl;
    return 0;
}
/*
7 11
0 1
0 2
0 4
1 2
1 3
2 3
2 4
2 5
2 6
3 6
5 6 */