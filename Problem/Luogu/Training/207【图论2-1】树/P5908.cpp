/**
 * @file    :   P5908 猫猫和企鹅
 * @author  :   Tanphoon
 * @date    :   2023/04/27 15:24
 * @version :   2023/04/27 15:24
 * @link    :   https://www.luogu.com.cn/problem/P5908
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, d;
vector<int> G[N];

int dfs(int u, int fa, int dep) {
    if (dep > d)
        return 0;
    int s = 1;
    for (int v : G[u])
        if (v != fa)
            s += dfs(v, u, dep + 1);
    return s;
}

int main() {
    cin >> n >> d;
    while (n--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << dfs(1, 0, 0) - 1;
    return 0;
}