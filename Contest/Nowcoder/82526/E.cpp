/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2024/05/26 21:01
 * @version :   2024/05/26 21:01
 * @link    :   https://ac.nowcoder.com/acm/contest/82526/E
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    if (n < 8) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 5; i <= n; i++)
        cout << i << ' ';
    if (n & 1) {
        cout << "2 1 4 3" << '\n';
    } else {
        cout << "1 2 3 4" << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}