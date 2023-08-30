/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/08/30 08:02
 * @version :   2023/08/30 08:02
 * @link    :   https://ac.nowcoder.com/acm/contest/39114/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count0(ll n) {
    ll sum = 1;
    for (ll fac = 1; n / fac; fac *= 10) {
        ll low = n - (n / fac) * fac;
        ll cur = (n / fac) % 10;
        ll high = n / (fac * 10);
        if (cur == 0)
            sum += (high - 1) * fac + low + 1;
        else
            sum += high * fac;
    }
    return sum;
}
int main() {
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = n + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        (count0(n) - count0(mid - 1) >= k) ? l = mid : r = mid;
    }
    if (count0(n) < k) {
        cout << -1 << '\n';
        return 0;
    }
    cout << r << '\n';
}