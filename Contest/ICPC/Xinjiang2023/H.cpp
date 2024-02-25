/** 
 * @file    :   H
 * @author  :   Tanphoon 
 * @date    :   2024/01/22 14:43
 * @version :   2024/01/22 14:43
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/B
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int s = b;
    if (a > 1) 
        s += (n + (n + 1) - (a - 1)) * (a - 1) / 2;
    s %= 26;
    cout << s + 'A' << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}