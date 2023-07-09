/** 
 * @file    :   1821A
 * @author  :   Tanphoon 
 * @date    :   2023/07/09 13:50
 * @version :   2023/07/09 13:50
 * @link    :   https://codeforces.com/contest/1821/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    if (s[0] == '?') 
        ans = 9;
    else if(s[0] == '0')
        ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '?')
            ans *= 10;
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}