/** 
 * @file    :   E - 矩阵游戏
 * @author  :   Tanphoon 
 * @date    :   2023/05/14 09:42
 * @version :   2023/05/14 09:42
 * @link    :   https://codeforces.com/gym/104354/problem/E
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector f(2, vector<vector<int>>(m + 1, vector<int>(x + 1)));
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] = " " + s[i];

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= x; k++) {
                if (s[i][j] == '0')
                    f[i & 1][j][k] = max(f[i & 1][j - 1][k], f[(i - 1) & 1][j][k]);
                else if (s[i][j] == '1')
                    f[i & 1][j][k] = max(f[i & 1][j - 1][k], f[(i - 1) & 1][j][k]) + 1;
                else {
                    if (k >= 1)
                        f[i & 1][j][k] = max(f[i & 1][j - 1][k - 1], f[(i - 1) & 1][j][k - 1]) + 1;
                    else
                        f[i & 1][j][k] = max(f[i & 1][j - 1][k], f[(i - 1) & 1][j][k]);
                }
                if (i == n && j == m)
                    res = max(res, f[i & 1][j][k]);
            }
        }
    }

    cout << res << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}
