/** 
 * @file    :   C
 * @author  :   Tanphoon 
 * @date    :   2024/02/02 15:21
 * @version :   2024/02/02 15:21
 * @link    :   https://ac.nowcoder.com/acm/contest/67741/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    ll n, q, t;
    cin >> n >> q >> t;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    while (q--) {
        ll m;
        cin >> m;
        int l = -1, r = n + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            (n - mid) * t <= m ? r = mid : l = mid;
        }
        cout << a[r] + t << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}       