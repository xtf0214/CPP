/** 
 * @file    :   503
 * @author  :   Tanphoon 
 * @date    :   2024/02/29 19:23
 * @version :   2024/02/29 19:23
 * @link    :   https://www.acwing.com/problem/content/505/
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<array<int, 3>> b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    auto check = [&](int x) {
        vector<int> c(n + 2);
        for (int i = 1; i <= x; i++) {
            int d = b[i][0], s = b[i][1], t = b[i][2];
            c[s] += d;
            c[t + 1] -= d;
        }
        for (int i = 1; i <= n; i++) {
            c[i] += c[i - 1];
            if (c[i] > a[i])
                return false;
        }
        return true;
    };
    int l = 0, r = m + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        check(mid) ? l = mid : r = mid;
    }
    if (r == m + 1) {
        cout << 0 << '\n';
    } else {
        cout << -1 << '\n';
        cout << r << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}