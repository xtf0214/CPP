/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/07/20 00:39
 * @version :   2023/07/20 00:39
 * @link    :   https://codeforces.com/contest/1837/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    char x = '0';
    for (auto &c : s) {
        if (c == '?')
            c = x;
        x = c;
    }
    cout << s << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}