/** 
 * @file    :   A
 * @author  :   Tanphoon 
 * @date    :   2024/05/07 22:56
 * @version :   2024/05/07 22:56
 * @link    :   https://codeforces.com/gym/102803/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double pi = acos(-1);

void solve() {
    ll a, b;
    cin >> a >> b;
    cout << pi * a * a + 4 * a * b << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) 
        solve();
    return 0;
}