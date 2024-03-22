/**
 * @file    :   1542C
 * @author  :   Tanphoon
 * @date    :   2023/11/21 22:55
 * @version :   2023/11/21 22:55
 * @link    :   https://codeforces.com/contest/1542/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
inline void solve() {
    ll n;
    cin >> n;
    ll LCM = 1, ans = 0;
    // f(x) = i ==> lcm(1,2,...,i-1)|x and lcm(1,2,...,i)!|x
    for (ll i = 1; i <= n; i++) {
        LCM = lcm(LCM, i);
        if (LCM > n)
            break;
        ans = (ans + n / LCM) % mod;
    }
    cout << (ans + n) % mod << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}