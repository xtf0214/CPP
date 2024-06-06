/** 
 * @file    :   M
 * @author  :   Tanphoon
 * @date    :   2024/05/12 13:53
 * @version :   2024/05/12 13:53
 * @link    :   https://codeforces.com/gym/105158/problem/M
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    auto check = [&](ll x) {
        ll mn = 2e18, mx = -2e18;
        // 每个数字的取值范围是 [a[i] - x * b[i], a[i] + x * b[i]]
        // 是否存在交集？max{a[i] - x * b[i]} >= min{a[i] + x * b[i]}
        for (int i = 0; i < n; i++) {
            mn = min(mn, a[i] + x * b[i]);
            mx = max(mx, a[i] - x * b[i]);
        }
        return mn >= mx;
    };
    ll l = -1, r = 1e9 + 1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        check(mid) ? r = mid : l = mid;
    }
    cout << r << '\n';
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}