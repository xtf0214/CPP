/**
 * @file    :   Educational Codeforces Round 150 (Rated for Div. 2) 1841B
 * @author  :   Tanphoon
 * @date    :   2023/06/21 17:41
 * @version :   2023/06/21 17:41
 * @link    :   https://codeforces.com/contest/1841/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a, mx, mn, last;
    cin >> a;
    mx = mn = last = a;
    bool up = true;
    cout << '1';
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (up && a >= mx) {
            mx = last = a;
            cout << '1';
        } else if (up && a <= mn) {
            up = false;
            last = a;
            cout << '1';
        } else if (!up && last <= a && a <= mn) {
            up = false;
            last = a;
            cout << '1';
        } else {
            cout << '0';
        }
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