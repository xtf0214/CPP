/**
 * @file    :   1816B
 * @author  :   Tanphoon
 * @date    :   2024/03/23 01:22
 * @version :   2024/03/23 01:22
 * @link    :   https://codeforces.com/contest/1816/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n;
    cin >> n;

    int ans[3][n + 1];

    ans[1][1] = 2 * n - 1;
    ans[2][n] = 2 * n;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            ans[1][i] = i;
            ans[2][i - 1] = i - 1;
        } else {
            ans[1][i] = n + (i - 1);
            ans[2][i - 1] = n + (i - 1) - 1;
        }
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " \n"[j == n];
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}