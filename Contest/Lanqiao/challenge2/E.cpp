/** 
 * @file    :   5
 * @author  :   Tanphoon 
 * @date    :   2023/10/28 23:53
 * @version :   2023/10/28 23:53
 * @link    :   https://www.lanqiao.cn/problems/5890/learning/?contest_id=145
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n + 1);
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        sum += 2 * w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<ll> dist(n + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto &[v, w] : G[u])
            if (v != fa) {
                dist[v] = dist[u] + w;
                dfs(v, u);
            }
    };
    dfs(1, 0);
    int ls = max_element(dist.begin(), dist.end()) - dist.begin();
    dist.assign(n + 1, 0);
    dfs(ls, 0);
    ll path = *max_element(dist.begin(), dist.end());
    cout << sum - path;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}