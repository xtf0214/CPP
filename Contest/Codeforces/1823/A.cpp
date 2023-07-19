/** 
 * @file    :   A
 * @author  :   Tanphoon 
 * @date    :   2023/07/19 23:33
 * @version :   2023/07/19 23:33
 * @link    :   https://codeforces.com/contest/1823/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int x = -1;
    for (int i = 0; i <= n; i++)
        if (i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == k)
            x = i;
    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < x; i++)
            cout << 1 << ' ';
        for (int i = 0; i < n - x; i++)
            cout << -1 << ' ';
        cout << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}