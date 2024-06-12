/**
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2024/06/11 18:48
 * @version :   2024/06/11 18:48
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> primes{2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,
                   53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                   127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197,
                   199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                   283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
                   383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
                   467, 479, 487, 491, 499, 503, 509, 521, 523, 541};
// 计算n!中素因子a的个数
// ans = n/a + n/a^2 + ... + n/a^k, k = log(n, 2)
ll f(ll n, ll a) {
    ll ans = 0;
    for (__int128_t i = a; i <= a; i *= a)
        if (i <= a)
            ans += n / i;
    return ans;
    // if (n < a)
    //     return 0;
    // return n / a + f(n / a, a);
}
inline void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    // 二分必须倒序计算来优化
    for (int i = n - 1; i >= 0; i--) {
        if (f(ans, primes[i]) >= a[i])
            continue; // 剪枝避免重复计算
        ll l = ans - 1, r = ll(1e18) + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            f(mid, primes[i]) >= a[i] ? r = mid : l = mid;
        }
        ans = max(ans, r);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}