/** 
 * @file    :   A
 * @author  :   Tanphoon 
 * @date    :   2024/03/21 22:07
 * @version :   2024/03/21 22:07
 * @link    :   https://codeforces.com/contest/1945/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    ll ans = a;
    if (c < (3 - b % 3) % 3) {
        cout << -1 << '\n';
        return;
    }
    ans += (b + c + 2) / 3;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}