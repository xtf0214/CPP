/** 
 * @file    :   2013A
 * @author  :   Tanphoon
 * @date    :   2024/09/21 08:57
 * @version :   2024/09/21 08:57
 * @link    :   https://codeforces.com/contest/2013/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include <DEBUG.h>
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5;

inline void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 0)
        cout << 0 << '\n';
    else
        cout << (n - 1) / min(x, y) + 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}