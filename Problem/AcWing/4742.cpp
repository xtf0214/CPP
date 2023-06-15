/** 
 * @file    :   4742. 电
 * @author  :   Tanphoon 
 * @date    :   2023/06/15 14:30
 * @version :   2023/06/15 14:30
 * @link    :   https://www.acwing.com/problem/content/4745/
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    function<int(int)> dfs = [&](int u) {
        if (s[u])
            return s[u];
        s[u] = 1;
        for (int v : G[u])
            if (a[u] > a[v]) {
                s[u] += dfs(v);
            }
        return s[u];
    };
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dfs(i));
    }
    cout << mx << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}