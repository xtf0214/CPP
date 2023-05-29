/**
 * @file    :   Educational Codeforces Round 149 (Rated for Div. 2) A
 * @author  :   Tanphoon
 * @date    :   2023/05/28 15:10
 * @version :   2023/05/28 15:10
 * @link    :   https://codeforces.com/contest/1837/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, k;
    cin >> x >> k;
    if (x % k != 0) {
        cout << 1 << endl;
        cout << x << endl;
        return;
    }
    for (int i = 1; i <= x; i++)
        if (i % k != 0 && (x - i) % k != 0) {
            cout << 2 << endl;
            cout << i << " " << (x - i) << endl;
            return;
        }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}