/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/09/16 05:01
 * @version :   2024/09/16 05:01
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    ll ans = s / n;
    ll t = s % n;
    if (t) {
        ll id = -1;
        for (int i = 0;; i++) {
            if (!(ans >> i & 1)) {
                id = i;
                break;
            }
        }
        ans -= (1LL << id) - 1;
        ll q = ans;
        ans += 1LL << id;
        if ((s - q) % (1 << id))
            ans++;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}