/**
 * @file    :   D 小蓝的新技能
 * @author  :   Tanphoon
 * @date    :   2023/06/07 10:51
 * @version :   2023/06/07 10:51
 * @link    :   https://ac.nowcoder.com/acm/contest/37782/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get(ll x) {
    ll l = 1, r = 1e6;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (m * m * m <= x) ? l = m : r = m;
    }
    return l; // 满足 t**3 <= x 的最大t
}

int main() {
    ll n, ans = 0;
    cin >> n;
    // 根据(gcd(a,b))**n == gcd(a**n, b**n)
    // 枚举所有满足 g**3 + k**3 == n 的 (g, k)
    // 然后枚举 g 的所有倍数 a , 计算满足 (g * k % a == 0) 的 b = g * k / a
    // 如果满足 gcd(a, b) == g , 则 (a, b) 为一个答案
    for (ll g = 1; g * g * g <= n; g++) {
        if (ll k = get(n - g * g * g); k * k * k + g * g * g == n) {
            for (ll a = g; a * a * a <= n; a += g) {
                if (k * g % a)
                    continue;
                ll b = k * g / a;
                cout << a << " " << b << '\n';
                if (__gcd(a, b) == g) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}