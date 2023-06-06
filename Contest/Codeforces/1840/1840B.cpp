/**
 * @file    :   Codeforces Round 878 (Div. 3) 1840B
 * @author  :   Tanphoon
 * @date    :   2023/06/06 22:59
 * @version :   2023/06/06 22:59
 * @link    :   https://codeforces.com/contest/1840/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int read(int x = 0) { return cin >> x, x; }

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k >= 32) {
        cout << n + 1 << '\n';
        return;
    }
    ll s = (1 << k) - 1;
    cout << min(n, s) + 1 << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}