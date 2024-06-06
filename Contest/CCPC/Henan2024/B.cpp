/** 
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/05/12 13:53
 * @version :   2024/05/12 13:53
 * @link    :   https://codeforces.com/gym/105158/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[n] = a[n];
    int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        f[i] = min(f[i + 1], a[i]);
    }
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        if (i - pre >= f[i])
            ans++, pre = i;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}