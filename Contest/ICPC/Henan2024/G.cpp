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
    ll l = 0, r = n / 2 + 1;
    while (r - l > 2) {
        ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        (f(n, m1) > f(n, m2)) ? r = m2 : l = m1;
    }
    ll ans = (l + r) / 2;
    cout << f(n, ans) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}