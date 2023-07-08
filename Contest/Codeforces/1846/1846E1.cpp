/**
 * @file    :   1846E1
 * @author  :   Tanphoon
 * @date    :   2023/07/07 23:59
 * @version :   2023/07/07 23:59
 * @link    :   https://codeforces.com/contest/1846/problem/E1
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ksm(ll a, ll b) {
    ll s = 1;
    for (; b; a = a * a, b >>= 1)
        if (b & 1)
            s *= a;
    return s;
}
ll calc(ll k, ll x) { return (ksm(k, x + 1) - 1) / (k - 1); }
void solve() {
    ll n;
    cin >> n;
    auto check = [&](ll k, ll x) { return calc(k, x) < n; };
    bool ok = false;
    // for (ll k = 1; k <= 1e6; k++) {
    //     int x = log(n) / log(k);
    //     for (int i = max(2, x - 2); i <= x + 2; i++)
    //         if (calc(k, i) == n) {
    //             ok = true;
    //             break;
    //             // cerr << k << ' ' << i << ' ' << calc(k, i) << '\n';
    //         }
    // }
    for (int k = 2; k <= 1e6; k++) {
        ll l = 1, r = log(n) / log(k) + 1, mid;
        while (r - l > 1) {
            if (check(k, mid = (l + r) / 2))
                l = mid;
            else
                r = mid;
        }
        if (calc(k, r) == n) {
            ok = true;
            break;
        }
    }
    puts(ok ? "YES" : "NO");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}