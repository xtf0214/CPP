/**
 * @file    :   G
 * @author  :   Tanphoon
 * @date    :   2024/06/08 16:55
 * @version :   2024/06/08 16:55
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
ll f(ll n, ll x) { return (n - 2 * x) * (n - 2 * x - 1) / 2 * x; }
inline void solve() {
    ll n;
    cin >> n;
    if (n <= 3) {
        cout << 0 << '\n';
        return;
    }
    double x = (2.0 * n - 1 - sqrt(n * n - n + 1)) / 6.0;
    ll ans = 0, mx = 0;
    for (int i = x - 1; i <= x + 1; i++) 
        ans = max(ans, f(n, i));
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