/**
 * @file    :   1860A
 * @author  :   Tanphoon
 * @date    :   2023/08/18 19:40
 * @version :   2023/08/18 19:40
 * @link    :   https://codeforces.com/contest/1860/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s == "()") {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    bool nest = false;
    int n = s.size();
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            nest = true;
    if (!nest) {
        cout << string(n, '(') + string(n, ')') << '\n';
    } else {
        for (int i = 0; i < n; i++)
            cout << "()";
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