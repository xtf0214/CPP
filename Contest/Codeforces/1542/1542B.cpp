/**
 * @file    :   1542B
 * @author  :   Tanphoon
 * @date    :   2023/11/21 22:46
 * @version :   2023/11/21 22:46
 * @link    :   https://codeforces.com/contest/1542/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

ll a, b, n;

inline void solve() {
    cin >> n >> a >> b;
    // if n in S, then n = a ** x + y * b, exist x, y >= 0
    if (a == 1) {
        if ((n - 1) % b == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    } else {
        for (ll t = 1; t <= n; t = t * a)
            if (t % b == n % b) {
                cout << "YES\n";
                return;
            }
        cout << "NO\n";
    }    
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}