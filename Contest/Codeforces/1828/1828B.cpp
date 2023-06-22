/**
 * @file    :   1828B
 * @author  :   Tanphoon
 * @date    :   2023/06/22 18:58
 * @version :   2023/06/22 18:58
 * @link    :   https://codeforces.com/contest/1828/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != i)
            ans = gcd(ans, abs(x - i));
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