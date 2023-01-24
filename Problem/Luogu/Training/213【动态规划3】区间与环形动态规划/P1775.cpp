/**
 * @file    :   P1775 石子合并（弱化版）
 * @author  :   Tanphoon
 * @date    :   2023/01/24 10:02
 * @version :   2023/01/24 10:02
 * @link    :   https://www.luogu.com.cn/problem/P1775
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

int n;
vector<int> a;
vector<vector<int>> f, w;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    a.resize(n + 1);
    f.assign(n + 1, vector<int>(n + 1));
    w.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            w[i][j] = w[i][j - 1] + a[j];
    for (int L = 1; L < n; L++)
        for (int i = 1, j = 1 + L; j <= n; i++, j++) {
            f[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            f[i][j] += w[i][j];
        }
    cout << f[1][n];
    return 0;
}