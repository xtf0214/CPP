/** 
 * @file    :   3
 * @author  :   Tanphoon 
 * @date    :   2023/10/28 23:51
 * @version :   2023/10/28 23:51
 * @link    :   https://www.lanqiao.cn/problems/5888/learning/?contest_id=145
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    sort(d.begin() + 2, d.end());
    int ans = 0;
    ans = a[n] - a[1];
    for (int i = 1; i < k; i++)
        ans -= d[n + 1 - i];
    cout << ans << '\n';
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}