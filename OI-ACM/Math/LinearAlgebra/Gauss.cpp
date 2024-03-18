/** 
 * @file    :   高斯消元法
 * @author  :   Tanphoon 
 * @date    :   2024/03/18 22:21
 * @version :   2024/03/18 22:21
 * @link    :   https://www.luogu.com.cn/problem/P3389
 */
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;

// a:增广矩阵 n*(n+1)
int gauss(vector<vector<double>> &a, int n) {
    for (int i = 0; i < n; i++) { // 枚举列
        int r = i;                // 该列最大数所在的行
        for (int j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[r][i]))
                r = j;
        if (abs(a[r][i]) < eps)
            return 0;     // 列最大数为0，无解
        swap(a[i], a[r]); // 把这一行移上来
        for (int j = n; j >= i; j--) a[i][j] /= a[i][i];     // 这一行的主元系数变为1
        for (int j = 0; j < n; j++) // 消去主元所在列的其他行的主元
            if (j != i && abs(a[j][i]) > eps)
                for (int k = n; k >= i; k--)
                    a[j][k] -= a[i][k] * a[j][i] / a[i][i];
    }
    return 1;
}
int main() {
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];
    if (!gauss(a, n)) {
        cout << "No Solution" << '\n';
    } else {
        for (int i = 0; i < n; i++)
            printf("%.2lf\n", a[i][n]);
    }
}