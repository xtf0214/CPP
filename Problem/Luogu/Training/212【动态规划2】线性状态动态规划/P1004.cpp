/**
 * @file    :   P1004 [NOIP2000 提高组] 方格取数
 * @author  :   Tanphoon
 * @date    :   2023/01/12 17:43
 * @version :   2023/01/13 09:28
 * @link    :   https://www.luogu.com.cn/problem/P1004
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5, INF = 0x3f3f3f3f;

int f[2 * N][N][N], a[N][N], n;
int main() {
    cin >> n;
    for (int y, x, k; cin >> y >> x >> k && y != 0 && x != 0 && k != 0;)
        a[y][x] = k;
    for (int s = 2; s <= n + n; s++)
        for (int i = max(s - n, 1); i <= min(n, s - 1); i++)
            for (int k = max(s - n, 1); k <= min(n, s - 1); k++) {
                f[s][i][k] = max({f[s - 1][i][k], f[s - 1][i - 1][k], f[s - 1][i][k - 1], f[s - 1][i - 1][k - 1]});
                f[s][i][k] += a[i][s - i] + a[k][s - k] * (i != k);
            }
    cout << f[n + n][n][n] << endl;
    return 0;
}