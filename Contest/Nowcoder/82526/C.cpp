/** 
 * @file    :   C
 * @author  :   Tanphoon 
 * @date    :   2024/05/26 20:06
 * @version :   2024/05/26 20:06
 * @link    :   https://ac.nowcoder.com/acm/contest/82526/C
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    string s;
    cin >> s;
    vector<int> a{0};
    int n = s.size();
    for (char c : s) 
        a.push_back(c - '0');
    int ans = 0;
    for (int i = n; i > 1; i--) {
        a[i - 1] += a[i] / 10;
        a[i] %= 10;
        if (a[i] != 0) {
            ans += 10 - a[i];
            a[i] = 0;
            a[i - 1] += 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}