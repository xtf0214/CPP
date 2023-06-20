/**
 * @file    :   Codeforces Round 881 (Div. 3) 1843D
 * @author  :   Tanphoon
 * @date    :   2023/06/20 23:49
 * @version :   2023/06/20 23:49
 * @link    :   https://codeforces.com/contest/1843/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> son(n + 1);
    function<int(int, int)> dfs = [&](int u, int fa) {
        if (G[u].size() == 1 && G[u][0] == fa)
            return son[u] = 1;
        int s = 0;
        for (int v : G[u])
            if (v != fa)
                s += dfs(v, u);
        return son[u] = s;
    };
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << 1LL * son[a] * son[b] << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}