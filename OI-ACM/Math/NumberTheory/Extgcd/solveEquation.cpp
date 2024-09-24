/**
 * @file    :   同余方程
 * @author  :   Tanphoon
 * @date    :   2024/06/07 12:09
 * @version :   2024/06/07 12:09
 * @link    :   https://www.luogu.com.cn/problem/P5656
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
int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, c, x, y;
        cin >> a >> b >> c;
        vector<ll> ans = solveEquation(a, b, c, x, y);
        for (ll i : ans)
            cout << i << ' ';
        cout << '\n';
    }
}