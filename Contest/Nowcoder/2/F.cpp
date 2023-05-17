/**
 * @file    :   F 手办
 * @author  :   Tanphoon
 * @date    :   2023/05/18 02:55
 * @version :   2023/05/18 02:55
 * @link    :   https://ac.nowcoder.com/acm/contest/37344/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n, ans = 1;
    cin >> n;
    for (ll i = 2, cnt; i * i * i <= n; i++) {
        if (n % i == 0) {
            for (cnt = 0; n % i == 0; cnt++)
                n /= i;
            ans *= (cnt / 3 + 1);
        }
    }
    // for (ll i = 1; i * i * i <= n; i++)
    //     if (n % (i * i * i) == 0)
    //         ans++;
    cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}