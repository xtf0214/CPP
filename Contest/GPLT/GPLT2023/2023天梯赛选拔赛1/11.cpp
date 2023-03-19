#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 100 + 5;
int n;
vector<int> G[N];
int indeg[N];

bool tsort() {
    queue<int> q;
    vector<int> ans;
    for (int u = 1; u <= n; u++)
        for (int v : G[u])
            indeg[v]++;
    for (int u = 1; u <= n; u++)
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
    return ans.size() == n;
}
int main() {
    cin >> n;
    for (int v = 1; v <= n; v++) {
        int m, u;
        cin >> m;
        while (m--) {
            cin >> u;
            G[u].push_back(v);
        }
    }
    cout << tsort();
}