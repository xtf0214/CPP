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

int calc(ll x) {
    int s = 0;
    while (x)
        s += x % 10, x /= 10;
    return s % 9;
}

inline void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector cnt(9, vector<int>(10));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int sum = calc(a[i]);
        cnt[sum][a[i] % 10]++;
    }
    ll ans = 0;
    for (ll x : a) {
        int sum = calc(x);
        cnt[sum][x % 10]--;
        if (x / 10 > 0) { // 两位数
            if (x % 100 % 4 == 0)
                for (int i = 0; i < 10; i++)
                    ans += cnt[(9 - sum) % 9][i];
        } else { // 一位数
            for (int i = 0; i < 10; i++)
                if ((i * 10 + x % 10) % 4 == 0)
                    ans += cnt[(9 - sum) % 9][i];
        }
        cnt[sum][x % 10]++;
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