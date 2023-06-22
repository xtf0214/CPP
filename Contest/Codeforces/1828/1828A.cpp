/**
 * @file    :   1828A
 * @author  :   Tanphoon
 * @date    :   2023/06/22 18:58
 * @version :   2023/06/22 18:58
 * @link    :   https://codeforces.com/contest/1828/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
    } else {
        for (int i = 1; i <= n; i++)
            cout << i * 2 << ' ';
    }
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}