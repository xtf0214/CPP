/**
 * @file    :   4
 * @author  :   Tanphoon
 * @date    :   2023/12/12 00:22
 * @version :   2023/12/12 00:22
 * @link    :   https://www.lanqiao.cn/problems/6280/learning/?contest_id=146
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector f(n + 1, vector(m + 1, vector<ll>(q + 1, -2e18)));
    vector a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    f[1][1][0] = a[1][1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int left = gcd(a[i][j], a[i - 1][j]);
            int up = gcd(a[i][j], a[i][j - 1]);
            for (int k = 0; k <= q; k++) {
                if (left == 1) {
                    if (k >= 1)
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + a[i][j]);
                } else {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i][j]);
                }
                if (up == 1) {
                    if (k >= 1)
                        f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 1] + a[i][j]);
                } else {
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k] + a[i][j]);
                }
            }
        }
    ll res = 0;
    for (int k = 0; k <= q; k++)
        res = max(res, f[n][m][k]);
    if (!res)
        cout << -1 << '\n';
    else
        cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}