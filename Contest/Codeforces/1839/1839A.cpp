/**
 * @file    :   Codeforces Round 876 (Div. 2) 1839A
 * @author  :   Tanphoon
 * @date    :   2023/06/03 22:43
 * @version :   2023/06/03 22:43
 * @link    :   https://codeforces.com/contest/1839/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = (n + k - 1) / k;
    if (k > 1 && n % k != 1)
        ans++;
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