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
    vector<int> a(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll x = 0;
    // f[i]=0表示+a[i]，f[i]=表示*a[i]
    // x 作为一个标记，表示每次计算完的x是否是一个大于1的数
    // 如果>1，那么就选择乘，否则就加
    for (int i = 0; i < n; i++) {
        if (i == 0 || x + a[i] > x * a[i]) {
            x += a[i];
            f[i] = 0;
        } else {
            x *= a[i];
            f[i] = 1;
        }
        x = min(2LL, x);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (f[i] == 0) {
            ans = (ans + a[i]) % mod;
        } else {
            ans = (ans * a[i]) % mod;
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