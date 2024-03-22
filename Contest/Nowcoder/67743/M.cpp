/**
 * @file    :   M
 * @author  :   Tanphoon
 * @date    :   2024/02/26 23:21
 * @version :   2024/02/26 23:21
 * @link    :   https://ac.nowcoder.com/acm/contest/67743/M
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), len(n);
    vector<int> p(20);
    p[0] = 1;
    for (int i = 1; i < 20; i++)
        p[i] = 10 * p[i - 1] % 36;
    vector<int> cnt(36);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        len[i] = to_string(a[i]).size();
        a[i] %= 36;
        ++cnt[a[i]];
    }
    // (x..y)%36=x*(10^len(y))%36+y%36=x*p[len(y)]%36+y%36
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        --cnt[a[i]];
        for (int j = 0; j < 36; j++) // 其他的所有情况
            if ((j * p[len[i]] + a[i]) % 36 == 0) {
                ans += cnt[j];
            }
        ++cnt[a[i]];
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}