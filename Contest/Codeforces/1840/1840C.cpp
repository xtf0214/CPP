/**
 * @file    :   Codeforces Round 878 (Div. 3) 1840C
 * @author  :   Tanphoon
 * @date    :   2023/06/06 23:17
 * @version :   2023/06/06 23:17
 * @link    :   https://codeforces.com/contest/1840/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > q)
            a[i] = 0;
        else
            a[i] = a[i - 1] + 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > 0 && a[i + 1] == 0)
            if (a[i] >= k) {
                ll t = a[i] - k + 1;
                ans += t * (t + 1) / 2;
            }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}