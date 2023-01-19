/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2023/01/18 14:13
 * @version :   2023/01/18 14:13
 * @link    :   https://ac.nowcoder.com/acm/contest/46810/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
void solve() {
    cin >> n;
    vector<int> a(n);
    vector<ll> pre(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    m = lower_bound(a.begin(), a.end(), 0) - a.begin();
    pre[0] = a[0];
    for (int i = 1; i < m; i++)
        pre[i] = pre[i - 1] + a[i];
    pre[m] = a[m];
    for (int i = m + 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] + a[i]);
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        if (i < m)
            tmp += abs(pre[m - 1] - pre[i]) + abs(pre[n - 1]);
        else if (i >= m)
            tmp += abs(pre[n - 1] - pre[i]);
        tmp += 1LL * (n - 1 - i) * abs(a[i]);
        ans += tmp * 2;
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}