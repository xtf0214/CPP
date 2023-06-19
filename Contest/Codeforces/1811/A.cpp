/**
 * @file    :   Codeforces Round 863 (Div. 3) A. Insert Digit
 * @author  :   Tanphoon
 * @date    :   2023/04/04 22:38
 * @version :   2023/04/04 22:38
 * @link    :   https://codeforces.com/contest/1811/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0' >= d) {
            cout << s[i];
        } else {
            cout << d;
            for (int j = i; j < n; ++j) {
                cout << s[j];
            }
            cout << '\n';
            return;
        }
    }
    cout << d << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}