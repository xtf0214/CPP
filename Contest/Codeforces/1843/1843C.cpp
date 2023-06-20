/**
 * @file    :   Codeforces Round 881 (Div. 3) 1843C
 * @author  :   Tanphoon
 * @date    :   2023/06/20 23:24
 * @version :   2023/06/20 23:24
 * @link    :   https://codeforces.com/contest/1843/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll x;
    cin >> x;
    ll ans = 0;
    while (x) {
        ans += x;
        x /= 2;
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}