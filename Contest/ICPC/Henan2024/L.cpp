/** 
 * @file    :   L
 * @author  :   Tanphoon
 * @date    :   2024/06/12 14:04
 * @version :   2024/06/12 14:04
 * @link    :   
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
    int x;
    cin >> x;
    if (x <= 4) {
        cout << 4 - x << '\n';
        return;
    }
    int y = x;
    while (__builtin_popcount(x) > 4) {
        x += x & -x;
    }
    cout << x - y << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}