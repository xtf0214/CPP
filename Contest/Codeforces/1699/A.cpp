/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/11/06 22:07
 * @version :   2023/11/06 22:07
 * @link    :   https://codeforces.com/contest/1699/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        cout << -1 << '\n';
    } else {
        int t = n / 2;
        cout << t << ' ' << 0 << ' ' << 0 << '\n';
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