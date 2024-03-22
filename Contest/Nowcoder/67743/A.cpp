/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/02/26 12:31
 * @version :   2024/02/26 12:31
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    string s, t;
    cin >> s >> t;
    if (s[0] == t[0] || (s[0] ^ ' ') == t[0]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
