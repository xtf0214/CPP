/**
 * @file    :   P3205 [HNOI2010]合唱队
 * @author  :   Tanphoon
 * @date    :   2023/01/28 22:43
 * @version :   2023/01/28 22:43
 * @link    :   https://www.luogu.com.cn/problem/P3205
 */
#include <iostream>
#include <vector>
using namespace std;
const int mod = 19650827;
vector<vector<vector<int>>> f;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    f.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(2)));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        f[i][i][0] = 1;
    for (int L = 1; L <= n; L++)
        for (int i = 1, j = i + L; j <= n; i++, j++) {
            // 左侧进入的人
            if (a[i] < a[i + 1])
                f[i][j][0] += f[i + 1][j][0];
            if (a[i] < a[j])
                f[i][j][0] += f[i + 1][j][1];
            // 右侧进入的人
            if (a[j] > a[i])
                f[i][j][1] += f[i][j - 1][0];
            if (a[j] > a[j - 1])
                f[i][j][1] += f[i][j - 1][1];
            f[i][j][0] %= mod;
            f[i][j][1] %= mod;
        }
    cout << (f[1][n][0] + f[1][n][1]) % mod;
    return 0;
}
