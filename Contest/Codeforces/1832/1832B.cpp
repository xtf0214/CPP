/**
 * @file    :   1832B
 * @author  :   Tanphoon
 * @date    :   2023/06/23 18:16
 * @version :   2023/06/23 18:16
 * @link    :   https://codeforces.com/contest/1832/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    ll ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, a[n - (k - i)] - a[i * 2]);
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