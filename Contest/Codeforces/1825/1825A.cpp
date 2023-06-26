/**
 * @file    :   1825A
 * @author  :   Tanphoon
 * @date    :   2023/06/26 23:32
 * @version :   2023/06/26 23:32
 * @link    :   https://codeforces.com/contest/1825/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true, same = true;
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i] != s[i - 1])
            same = false;
        if (s[i] != s[n - 1 - i])
            ok = false;
    }
    if (same)
        cout << - 1 << '\n';
    else if (ok)
        cout << n - 1 << '\n';
    else 
        cout << n << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}