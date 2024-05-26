/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2024/05/26 20:16
 * @version :   2024/05/26 20:16
 * @link    :   https://ac.nowcoder.com/acm/contest/82526/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getFactor(int x) {
    int ans = 0;
    for (ll i = 1; i * i <= x; i++)
        if (x % i == 0) {
            ans++;
            if (i * i != x)
                ans++;
        }
    return ans;
}

inline void solve() {
    int n, q;
    cin >> n >> q;
    vector<array<int, 130>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1];
        int x;
        cin >> x;
        int s = getFactor(x);
        a[i][s] ++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        for (int i = 0; i < 130; i++) {
            ll s = a[r][i] - a[l - 1][i];
            ans += s * (s - 1) / 2;
        }
        cout << ans << '\n';
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