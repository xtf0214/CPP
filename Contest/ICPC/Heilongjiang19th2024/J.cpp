/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2024/05/29 01:01
 * @version :   2024/05/29 01:01
 * @link    :   https://codeforces.com/gym/105163/problem/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    vector<vector<ll>> sum(n + 1, vector<ll>(m + 1, 1e18));
    vector<vector<ll>> f(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    f[1][1] = a[1][1];
    sum[1][1] = b[1][1];
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (f[i][j]) {
                if (sum[i][j] + b[i + 1][j] + a[1][1] <= a[i + 1][j]) {
                    f[i + 1][j] = 1;
                    sum[i + 1][j] = min(sum[i + 1][j], sum[i][j] + b[i + 1][j]);
                }
                if (sum[i][j] + b[i][j + 1] + a[1][1] <= a[i][j + 1]) {
                    f[i][j + 1] = 1;
                    sum[i][j + 1] = min(sum[i][j + 1], sum[i][j] + b[i][j + 1]);
                }
            }
        }
    bool ok = false;
    for (int i = 1; i <= n; i++)
        ok |= f[i][m];
    for (int i = 1; i <= m; i++)
        ok |= f[n][i];
    cout << (ok ? "YES" : "NO") << '\n';
}