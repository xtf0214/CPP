/**
 * @file    :   P1854 花店橱窗布置
 * @author  :   Tanphoon
 * @date    :   2023/01/13 23:54
 * @version :   2023/01/13 23:54
 * @link    :   https://www.luogu.com.cn/problem/P1854
 */
#include <bits/stdc++.h>
using namespace std;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int INF = 0x3f3f3f3f;

int n, m;
int main() {
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> f(n + 1, vector<int>(m + 1, -INF));
    f[0].assign(m + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= m; j++)
            f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + a[i][j]);
    vector<int> ans;
    for (int i = n, r = m; i >= 1; i--) {
        while (f[i][r] == f[i][r - 1])
            r--;
        ans.push_back(r--);
    }
    reverse(ans.begin(), ans.end());
    cout << f[n][m] << endl;
    print(ans);
    return 0;
}