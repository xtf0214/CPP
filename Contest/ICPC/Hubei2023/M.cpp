/**
 * @file    :   M
 * @author  :   Tanphoon
 * @date    :   2023/12/17 16:04
 * @version :   2023/12/17 16:04
 * @link    :   https://codeforces.com/gym/104337/problem/M
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d;
    if (b == 0)
        x = 1, y = 0, d = a;
    else {
        d = extgcd(b, a % b, y, x); // x'  y'
        y -= a / b * x;             // y = y - a / b * x = x' - a / b * y' = y'' - a / b * y'
    }
    return d;
}
vector<ll> solveEquation(ll a, ll b, ll c, ll &x0, ll &y0) { // solve ax+by=c
    ll d = extgcd(a, b, x0, y0);
    if (c % d != 0)
        return {-1};
    x0 *= c / d, y0 *= c / d;
    ll p = b / d, q = a / d, k, x1, y1;
    k = ceil((1.0 - x0) / p);
    x0 = x0 + k * p, y0 = y0 - k * q; // (x0, y0) is (x_min, y_max) x_min > 0
    k = ceil((1.0 - y0) / q);
    x1 = x0 - k * p, y1 = y0 + k * q; // (x1, y1) is (x_max, y_min) y_min > 0
    if (y0 > 0) {
        return {-k + 1, x0, y1, x1, y0};
    } else {
        return {x0, y1};
    }
}
inline void solve() {
    ll n, m;
    cin >> n >> m;
    if (n == 0) {
        cout << "0 0 0" << '\n';
        return;
    }
    ll x, y, z;
    ll a = 1000, b = 2500;
    auto ans = solveEquation(a, b, m, y, z);
    if (ans[0] == -1) {
        cout << -1 << '\n';
        return;
    } else if (ans.size() == 5) {
        cout << n - ans[1] - ans[4] << ' ' << ans[1] << ' ' << ans[4] << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}