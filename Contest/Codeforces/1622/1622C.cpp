/** 
 * @file    :   1622C
 * @author  :   Tanphoon 
 * @date    :   2023/09/21 15:51
 * @version :   2023/09/21 15:51
 * @link    :   https://codeforces.com/contest/1622/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll floor(ll a, ll b) {
    ll c = a / b;
    while (c * b > a)
        c--;
    return c;
} 

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) 
        s[i] = s[i - 1] + a[i];
    ll ans = 1e18;
    for (ll y = 0; y < n; y++) {
        ll x = a[1] - floor(k - s[n - y] + a[1], y + 1);
        ans = min(ans, y + max(x, 0LL));
    }
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