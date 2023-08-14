#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> s(n), v(n);
    pair<ll, ll> mx{};
    for (int i = 0; i < n; i++)
        cin >> s[i] >> v[i];

    auto check = [&](ll x) {
        ll sum = 0, mx = 0;
        for (int i = 0; i < n; i++)
            if (x > s[i]) {
                ll t = (x - s[i]) * v[i];
                mx = max(mx, t);
                sum += t;
            }
        return sum - mx < m;
    };

    ll l = 0, r = 2e18 + 5, mid;
    for (int i = 1; i <= 10; i++)
        check(i);

    while (r - l > 1)
        check(mid = l + r >> 1) ? l = mid : r = mid;
    if (r == 2e18 + 5) {
        cout << -1 << '\n';
    } else {
        cout << r << '\n';
    }
    return 0;
}