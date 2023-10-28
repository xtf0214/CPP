/** 
 * @file    :   4
 * @author  :   Tanphoon 
 * @date    :   2023/10/28 23:53
 * @version :   2023/10/28 23:53
 * @link    :   https://www.lanqiao.cn/problems/5889/learning/?contest_id=145
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    ll P;
    cin >> n >> P;
    vector<vector<int>> G(n + 1);
    vector<int> s(n + 1), k(n + 1), depth(n + 1);
    for (int i = 1; i <= n; i++) {
        int f;
        cin >> f >> s[i] >> k[i];
        G[f].push_back(i);
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int ans = 0;
    q.push({k[1], 1});
    while (!q.empty()) {
        auto [ki, u] = q.top();
        q.pop();
        if (P < k[u])
            break;
        ans++;
        P += s[u];
        for (int v : G[u])
            q.push({k[v], v});
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}