/**
 * @file    :   1627C
 * @author  :   Tanphoon
 * @date    :   2023/10/09 21:10
 * @version :   2023/10/09 21:10
 * @link    :   https://codeforces.com/contest/1627/problem/C
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    vector<pair<int, int>> E;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        E.push_back({u, v});
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (G[i].size() >= 3) {
            cout << -1 << '\n';
            return;
        }
    int beg = 0;
    for (int i = 1; i <= n; i++)
        if (G[i].size() == 1) {
            beg = i;
            break;
        }
    int cur = 2;
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (int v : G[u])
            if (v != fa) {
                mp[{u, v}] = mp[{v, u}] = cur;
                cur = 5 - cur;
                dfs(v, u);
            }
    };
    dfs(beg, -1);
    for (auto &[u, v] : E)
        cout << mp[{u, v}] << ' ';
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}