/** 
 * @file    :   J
 * @author  :   Tanphoon 
 * @date    :   2023/08/10 17:30
 * @version :   2023/08/10 17:30
 * @link    :   https://ac.nowcoder.com/acm/contest/62977/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    vector<int> dep(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int fa) {
        dep[u] = dep[fa] + 1;
        for (int v : G[u])
            if (v != fa) {
                dfs(v, u);
            }
    };
    dfs(1, 0);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    sort(dep.begin() + 1, dep.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1LL * dep[i] * a[i];
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
