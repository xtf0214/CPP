/** 
 * @file    :   G
 * @author  :   Tanphoon 
 * @date    :   2024/02/02 13:38
 * @version :   2024/02/02 13:38
 * @link    :   https://ac.nowcoder.com/acm/contest/67741/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i].second;
    ll ans = m;
    for (int i = 1; i <= n; i++)
        if (s[i] + m >= a[i].first)
            ans = max(ans, s[i] + m);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}