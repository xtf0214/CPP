/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2023/08/09 13:14
 * @version :   2023/08/09 13:14
 * @link    :   https://ac.nowcoder.com/acm/contest/62977/D
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' || s[i] == '?')
            len++;
        if (s[i] == '0' || i == n - 1) {
            ans = max(ans, len);
            len = 0;
        }
    }
    len = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' || s[i] == '?')
            len++;
        if (s[i] == '1' || i == n - 1) {
            ans = max(ans, len);
            len = 0;
        }
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