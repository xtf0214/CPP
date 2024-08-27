/**
 * @file    :   树上直径
 * @author  :   Tanphoon
 * @date    :   2024/08/27 00:55
 * @version :   2024/08/27 00:55
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
vector<int> G[N];

int getlen(int root) { // 获取x所在树的直径
    vector<int> dep(n + 1);
    vector<int> p(n + 1, -1);
    function<void(int, int)> dfs = [&](int u, int fa) -> void {
        for (int v : G[u]) {
            if (v == fa)
                continue;
            dep[v] = dep[u] + 1;
            p[v] = u;
            dfs(v, u);
        }
        if (dep[u] > dep[root])
            root = u;
    };
    dfs(root, -1);
    int st = root; // 记录直径端点
    
    dep.assign(n + 1, 0);
    p.assign(n + 1, -1);
    dfs(root, -1);
    int ed = root; // 记录直径另一端点
    
    for (int i = ed; i != -1; i = p[i])
        i == st ? printf("%d", i) : printf("%d -> ", i);
    cout << endl;
    return dep[root];
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << getlen(0) << endl;
}
/* 
13
0 1
0 4
0 10
1 2
1 3
4 5
4 6
4 7
7 8
7 9
10 11
10 12
 */