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
int indeg[N], dep[N]; // dep[u]为u结点到起点距离，也就是u的深度
int n, m;
int mx, idx;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    dep[s] = 1;
    mx = 1, idx = s; // 存储最深结点编号以及它的深度
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int v : G[u]) {
            q.push(v);
            dep[v] = dep[u] + 1; // bfs搜索，子节点的深度为父节点的深度+1
            if (mx < dep[v])
                mx = dep[v], idx = v; // 更新最深结点
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
    int s = find(indeg + 1, indeg + n + 1, 0) - indeg; // 查找入度为0的结点，即为起点
    bfs(s);
    cout << idx;
}