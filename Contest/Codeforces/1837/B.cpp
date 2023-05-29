/**
 * @file    :   Educational Codeforces Round 149 (Rated for Div. 2) B
 * @author  :   Tanphoon
 * @date    :   2023/05/28 15:25
 * @version :   2023/05/28 15:25
 * @link    :   https://codeforces.com/contest/1837/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 1, res = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            cnt++;
        else
            cnt = 1;
        res = max(res, cnt);
    }
    cout << res + 1 << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}