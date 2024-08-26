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
    function<void(int, int)> dfs = [&](int u, int fa) -> void {
        for (int v : G[u]) {
            if (v == fa)
                continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
        if (dep[u] > dep[root]) {
            root = u;
        }
    };
    dfs(root, 0);
    int st = root; // 记录直径端点
    dep.assign(n + 1, 0);
    dfs(root, 0);
    int ed = root; // 记录直径另一端点
    return dep[root];
}
int main() {

}