#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d;
    if (b == 0)
        x = 1, y = 0, d = a;
    else {
        d = extgcd(b, a % b, y, x); // y = x',  x = y'
        y -= a / b * x;             // y = y - a / b * x = x' - a / b * y'
    }
    return d;
}

void minmax(ll a, ll b, ll c, ll n) {
    ll x0, y0, gcd = extgcd(a, b, x0, y0);
    if (c < 0) {
        cout << -1 << '\n';
        return;
    } else if (c == 0 && gcd == 0) {
        cout << 0 << ' ' << n << '\n';
        return;
    } else if (c == 0) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    } else if (gcd == 0 || c % gcd != 0) {
        cout << -1 << '\n';
        return;
    }
    // c > 0, gcd != 0, c % gcd == 0
    x0 *= c / gcd;
    y0 *= c / gcd;
    ll k_min = ceil(double(-x0) / (b / gcd));
    ll k_max = floor(double(y0) / (a / gcd));
    if (k_min > k_max) {
        cout << -1 << '\n';
        return;
    }
    ll x_min = 1e8, x_max = -1;
    for (ll k = k_min; k <= k_max; k++) {
        ll x_k = x0 + k * (b / gcd);
        ll y_k = y0 - k * (a / gcd);
        if (x_k + y_k <= n) {
            x_min = min(x_min, x_k);
            x_max = max(x_max, x_k);
        }
    }
    cout << x_min << ' ' << x_max << '\n';
}
signed main() {
    ll p, q, n1, n2, n3;
    cin >> p >> q >> n1 >> n2 >> n3;
    minmax(n3 - n1, n2 - n1, q - n1 * p, p);
}