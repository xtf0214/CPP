/**
 * @file    :   7-30 深入虎穴
 * @author  :   Tanphoon
 * @date    :   2023/04/17 23:59
 * @version :   2023/04/17 23:59
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
bool vis[N];
int indeg[N], dep[N];
int n, m;
int mx, idx;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dep[s] = 1;
    mx = 1, idx = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int v : G[u]) {
            q.push(v);
            dep[v] = dep[u] + 1;
            if (mx < dep[v])
                mx = dep[v], idx = v;
        }
    }
}
int main() {
    cin >> n;
    for (int u = 1; u <= n; u++) {
        int sz, v;
        cin >> sz;
        while (sz--) {
            cin >> v;
            indeg[v]++;
            G[u].push_back(v);
        }
    }
    int s = find(indeg + 1, indeg + n + 1, 0) - indeg;
    bfs(s);
    cout << idx;
}