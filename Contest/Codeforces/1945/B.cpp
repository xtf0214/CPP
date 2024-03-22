/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2024/03/21 23:44
 * @version :   2024/03/21 23:44
 * @link    :   https://codeforces.com/contest/1945/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    cout << (m + 1 + a - 1) / a + (m + 1 + b - 1) / b << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}