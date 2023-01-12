/**
 * @file    :   numberTriangles2
 * @author  :   Tanphoon
 * @date    :   2023/01/12 17:47
 * @version :   2023/01/12 17:47
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5, INF = 0x3f3f3f3f;
int a[N][N], f[N][N][N], n, K, ans = -INF;
int main() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int j = 1; j <= n; j++)
        f[n][j][0] = a[n][j], f[n][j][1] = a[n][j] * 3;
    for (int i = n - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            for (int k = 0; k <= K; k++) {
                f[i][j][k] = max(f[i + 1][j][k], f[i + 1][j + 1][k]) + a[i][j];
                if (k >= 1)
                    f[i][j][k] = max(f[i][j][k], max(f[i + 1][j][k - 1], f[i + 1][j + 1][k - 1]) + a[i][j] * 3);
            }
    for (int k = 0; k <= K; k++)
        ans = max(ans, f[1][1][k]);
    cout << ans;
    return 0;
}
/*
5 1
7
3 9
8 1 0
2 7 4 4
4 5 2 6 5
*/
// 47