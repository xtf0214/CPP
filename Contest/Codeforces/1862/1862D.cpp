/**
 * @file    :   1862D
 * @author  :   Tanphoon
 * @date    :   2023/08/25 00:00
 * @version :   2023/08/25 00:00
 * @link    :   https://codeforces.com/contest/1862/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll l = 0, r = 1e10, mid;
    while (r - l > 1) {
        mid = (l + r) >> 1;
        (mid * (mid - 1) / 2 < n) ? l = mid : r = mid;
    }
    if (r * (r - 1) / 2 == n)
        cout << r << endl;
    else
        cout << r - 1 + n - (r - 1) * (r - 2) / 2 << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}