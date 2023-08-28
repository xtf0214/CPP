/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/08/25 17:06
 * @version :   2023/08/25 17:06
 * @link    :   https://ac.nowcoder.com/acm/contest/63746/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1));
    vector f(n + m + 1, vector(n + 1, vector<ll>(n + 1)));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int s = 2; s <= m + n; s++)
        for (int i = max(s - m, 1); i <= min(s - 1, n); i++)
            for (int k = max(s - m, 1); k <= min(s - 1, n); k++) {
                f[s][i][k] = max({f[s - 1][i][k], f[s - 1][i - 1][k], f[s - 1][i][k - 1], f[s - 1][i - 1][k - 1]});
                f[s][i][k] += a[i][s - i] + a[k][s - k] * (i != k);
            }
    cout << f[m + n][n][n] << '\n';
}