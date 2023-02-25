/**
 * @file    :   CF607B Zuma 祖玛
 * @author  :   Tanphoon
 * @date    :   2023/01/24 23:38
 * @version :   2023/02/26 02:01
 * @link    :   https://www.luogu.com.cn/problem/CF607B
 */
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int n;
vector<int> a;
vector<vector<int>> f;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f.resize(n + 1, vector<int>(n + 1, INF));
    for (int L = 0; L < n; L++)
        for (int i = 1, j = i + L; j <= n; i++, j++) {
            if (a[i] == a[j])
                f[i][j] = (L < 2) ? 1 : min(f[i][j], f[i + 1][j - 1]);
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
    cout << f[1][n];
    return 0;
}