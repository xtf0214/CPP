/**
 * @file    :   P1833 樱花
 * @author  :   Tanphoon
 * @date    :   2023/01/14 20:43
 * @version :   2023/01/14 20:43
 * @link    :   https://www.luogu.com.cn/problem/P1833
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int hh1, mm1, hh2, mm2, W, n;
    scanf("%d:%d %d:%d %d", &hh1, &mm1, &hh2, &mm2, &n);
    W = (hh2 - hh1) * 60 + mm2 - mm1;
    vector<int> w(n + 1), v(n + 1), c(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i] >> c[i];
    for (int i = 1; i <= n; i++) {
        if (c[i])
            for (int j = 0; j <= W; j++)
                for (int k = 0; j - k * w[i] >= 0 && k <= c[i]; k++)
                    f[i][j] = max(f[i][j], f[i - 1][j - k * w[i]] + k * v[i]);
        else
            for (int j = 0; j <= W; j++)
                if (j - w[i] < 0)
                    f[i][j] = f[i - 1][j];
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i]);
    }
    cout << f[n][W];
    return 0;
}