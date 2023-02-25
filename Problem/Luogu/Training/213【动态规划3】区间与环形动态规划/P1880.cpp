/**
 * @file    :   P1880 [NOI1995] 石子合并
 * @author  :   Tanphoon
 * @date    :   2023/02/23 14:28
 * @version :   2023/02/23 14:28
 * @link    :   https://www.luogu.com.cn/problem/P1880
 */
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
vector<vector<int>> w, f1, f2;
vector<int> a;
int main() {
    cin >> n;
    w.resize(2 * n + 1, vector<int>(2 * n + 1));
    a.resize(2 * n + 1);
    f1.resize(2 * n + 1, vector<int>(2 * n + 1));
    f2.resize(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
        for (int j = i; j <= 2 * n; j++)
            w[i][j] = w[i][j - 1] + a[j];
    for (int L = 1; L < n; L++)
        for (int i = 1, j = i + L; j <= 2 * n; i++, j++) {
            f1[i][j] = INF, f2[i][j] = -INF;
            for (int k = i; k < j; k++) {
                f1[i][j] = min(f1[i][j], f1[i][k] + f1[k + 1][j]);
                f2[i][j] = max(f2[i][j], f2[i][k] + f2[k + 1][j]);
            }
            f1[i][j] += w[i][j];
            f2[i][j] += w[i][j];
        }
    int ans1 = INF, ans2 = -INF;
    for (int i = 1; i <= n; i++)
        ans1 = min(ans1, f1[i][i + n - 1]);
    for (int i = 1; i <= n; i++)
        ans2 = max(ans2, f2[i][i + n - 1]);
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}