/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2023/10/14 20:05
 * @version :   2023/10/14 20:05
 * @link    :   https://www.lanqiao.cn/problems/5130/learning/?contest_id=144
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> t(q + 1);
    for (int i = 1; i <= q; i++)
        cin >> t[i];
    t.push_back(n + 1);
    vector<ll> w(m + 1), v(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> w[i] >> v[i];
        w[i] = 1LL << w[i];
    }
    vector<ll> f(n + 1);
    for (int i = 1; i <= m; i++)
        for (int j = w[i]; j <= n; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    ll ans = 0;
    for (int i = 1; i <= q + 1; i++) {
        int x = t[i] - t[i - 1] - 1;
        ans += f[x];
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