/**
 * @file    :   L
 * @author  :   Tanphoon
 * @date    :   2024/05/15 13:13
 * @version :   2024/05/15 13:13
 * @link    :   https://codeforces.com/gym/105158/problem/L
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    vector<ll> s(m + 1);
    for (int i = 1; i <= m; i++)
        s[i] = s[i - 1] + a[i];
    int ans = 0;
    vector<ll> f(m + 1, 1e18);
    f[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= min(i, 20); j++) {
            f[i] = min({f[i - j] + j + s[i] - s[i - j], f[i - j] + a[i] + (ll)pow(j, 4), f[i]});
        }
    }
    cout << f[m] << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
}