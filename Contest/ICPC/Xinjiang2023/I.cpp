/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2024/01/22 17:21
 * @version :   2024/01/22 17:21
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/I
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        ans += i * i;
        v[i]--;
    }
    // deg n (n-1)*2
    int deg = (n - 1) * 2 - n;
    for (int i = 1; i <= n; i++) {
        if (v[i] >= deg)
            ans += deg * i * i;
        else
            ans += v[i] * i * i;
        deg -= v[i];
        if (deg <= 0)
            break;
    }
    if (deg <= 0)
        cout << ans << '\n';
    else
        cout << "-1\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}