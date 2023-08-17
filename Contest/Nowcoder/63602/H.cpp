/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2023/08/16 23:44
 * @version :   2023/08/16 23:44
 * @link    :   https://ac.nowcoder.com/acm/contest/63602/H
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector f = a;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    vector<int> mx(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1) {
                f[i][j] = a[i][j];
                mx[i] = max(mx[i], f[i][j]);
            } else {
                f[i][j] = f[i - 1][j];
                if (i - k >= 1)
                    f[i][j] = max(f[i][j], mx[i - k] + a[i][j]);
                mx[i] = max(mx[i], f[i][j]);
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++)
        ans = max(ans, f[n][j]);
    cout << ans << '\n';
    return 0;
}