/** 
 * @file    :   1605A
 * @author  :   Tanphoon 
 * @date    :   2023/11/23 22:38
 * @version :   2023/11/23 22:38
 * @link    :   https://codeforces.com/contest/1605/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min({abs(a + b - 2 * c) % 3, abs(a + c - 2 * b) % 3, abs(b + c - 2 * a) % 3}) << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}