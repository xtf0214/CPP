/** 
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/09/16 14:59
 * @version :   2024/09/16 14:59
 * @link    :   https://codeforces.com/gym/105139/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include <DEBUG.h>
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5;

inline void solve() {
    ll x, y;
    cin >> x >> y;
    ll g = gcd(x, y);
    cout << 1 << ' ' << x * y / g / g << '\n';   
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}