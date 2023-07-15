/**
 * @file    :   4
 * @author  :   Tanphoon
 * @date    :   2023/07/15 23:42
 * @version :   2023/07/15 23:42
 * @link    :   https://ac.nowcoder.com/acm/contest/60393/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    int st = 0;
    while (st < n && ans < 2)
        ans += a[st++];
    ans %= mod;
    for (int i = st; i < n; i++)
        if (a[i] < 2)
            ans = (ans + a[i]) % mod;
        else
            ans = (ans * a[i]) % mod;
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