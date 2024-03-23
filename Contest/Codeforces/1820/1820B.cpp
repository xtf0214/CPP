/**
 * @file    :   1820B
 * @author  :   Tanphoon
 * @date    :   2024/03/24 00:29
 * @version :   2024/03/24 00:29
 * @link    :   https://codeforces.com/contest/1820/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    s += s;
    ll lst = -1, maxlen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0')
            lst = i;
        else if (s[i] == '1')
            maxlen = max(maxlen, i - lst);
    }
    ll ans = 0;
    if (maxlen > n) {
        ans = n * n;
    } else {
        // for (ll i = 1; i <= maxlen; i++)
        //     ans = max(ans, i * (maxlen - i + 1));
        ans = ((maxlen + 2) / 2) * ((maxlen + 1) / 2);
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