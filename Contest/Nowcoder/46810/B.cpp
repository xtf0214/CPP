/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2023/01/18 13:18
 * @version :   2023/01/18 13:18
 * @link    :   https://ac.nowcoder.com/acm/contest/46810/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, l, r;
    cin >> n >> a >> b >> l >> r;
    int ans = min(r, n - a) - max(l, n - b) + 1;
    cout << (ans > 0 ? ans : 0) << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}