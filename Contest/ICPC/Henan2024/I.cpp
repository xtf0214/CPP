/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2024/06/12 15:55
 * @version :   2024/06/12 15:55
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/I
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    ll n;
    string s, t;
    cin >> n >> s >> t;
    int cnt = 0;
    if (t[0] == t[1]) {
        for (int i = 0; i < n; i++)
            cnt += (s[i] != t[0]);
        cout << n * (n - 1) / 2 << ' ' << cnt << '\n';
    } else {
        for (int i = 0; i < n / 2; i++)
            cnt += (s[i] != t[0]);
        for (int i = n - 1; i >= (n + 1) / 2; i--)
            cnt += (s[i] != t[1]);
        if (n & 1 == 1 && s[n / 2] != t[0] && s[n / 2] != t[1])
            cnt++;
        cout << n / 2 * ((n + 1) / 2) << ' ' << cnt << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}