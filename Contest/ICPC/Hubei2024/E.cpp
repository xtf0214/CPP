/** 
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2024/09/16 15:27
 * @version :   2024/09/16 15:27
 * @link    :   https://codeforces.com/gym/105139/problem/E
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    cout << (n - x) * a + x * b << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}