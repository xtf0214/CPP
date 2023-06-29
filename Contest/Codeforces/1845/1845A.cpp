/**
 * @file    :   1845A
 * @author  :   Tanphoon
 * @date    :   2023/06/30 01:25
 * @version :   2023/06/30 01:25
 *@link : https : // codeforces.com/contest/1845/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES\n";
        cout << n << '\n';
        for (int i = 0; i < n; i++)
            cout << 1 << ' ';
        cout << '\n';
    } else if (n % 2 == 0 && k >= 2) {
        cout << "YES\n";
        cout << n / 2 << '\n';
        for (int i = 0; i < n / 2; i++)
            cout << 2 << ' ';
        cout << '\n';
    } else if (k >= 3) {
        cout << "YES\n";
        cout << n / 2 << '\n';
        for (int i = 0; i < (n - 3) / 2; i++)
            cout << 2 << ' ';
        cout << 3 << ' ';
        cout << '\n';
    } else {
        cout << "NO\n";
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