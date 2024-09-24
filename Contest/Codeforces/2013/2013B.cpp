/**
 * @file    :   2013B
 * @author  :   Tanphoon
 * @date    :   2024/09/21 09:01
 * @version :   2024/09/21 09:01
 * @link    :   https://codeforces.com/contest/2013/problem/B
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
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    ans -= 2 * a[n - 2];    
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