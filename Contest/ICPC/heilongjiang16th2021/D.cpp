/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2024/04/23 00:33
 * @version :   2024/04/23 00:33
 * @link    :   https://codeforces.com/gym/103107/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e6 + 3;
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector f(n + 1, vector<int>(n + 1));
    vector g(n + 1, vector<int>(n + 1));

    for (int L = 1; L <= n; L++) {
        if (L == 1) {
            for (int i = 1; i <= n; i++) {
                g[i][i] = a[i];
            }
        } else {
            for (int i = 1, j = i + L - 1; i <= n && j <= n; i++, j++)
                for (int k = i; k < j; k++) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + (g[i][k] - g[k + 1][j]) * (g[i][k] - g[k + 1][j]));
                    g[i][j] = g[i][k] * g[k + 1][j] % mod;
                }
        }
    }
    cout << f[1][n] << '\n';
}