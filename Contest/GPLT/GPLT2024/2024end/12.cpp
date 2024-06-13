/** 
 * @file    :   L2-4 吉利矩阵
 * @author  :   Tanphoon
 * @date    :   2024/06/13 15:35
 * @version :   2024/06/13 15:35
 * @link    :   https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388427&page=1
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> row(n), col(n);
    int cnt = 0;
    int sum = 0;
    function<void(int)> dfs = [&](int cur) {
        if (cur == n * n) {
            if (count(row.begin(), row.end(), m) + count(col.begin(), col.end(), m) == 2 * n) {
                cnt++;
            }
            return;
        }
        int i = cur / n, j = cur % n;
        for (int k = 0; k <= min(m - row[i], m - col[j]); k++) {
            if (row[i] + k + m * (n - 1 - j) < m || col[j] + k + m * (n - 1 - i) < m)
                continue;
            a[i][j] = k;
            row[i] += k;
            col[j] += k;
            dfs(cur + 1);
            a[i][j] = 0;
            row[i] -= k;
            col[j] -= k;
        }
    };
    dfs(0);
    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}