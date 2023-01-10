#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> G;
vector<int> ans;

bool tsort() {
    vector<int> indeg(V + 1);
    queue<int> q;
    for (int u = 1; u <= V; u++)
        for (int v : G[u])
            indeg[v]++;
    for (int u = 1; u <= V; u++)
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
    return ans.size() == V;
}
signed main() {
    cin >> V;
    G.resize(V + 1);
    for (int v = 1, k; v <= V; v++) {
        cin >> k;
        for (int i = 0, u; i < k; i++)
            cin >> u, G[u].push_back(v);
    }
    cout << tsort() ? 1 : 0;
    return 0;
}