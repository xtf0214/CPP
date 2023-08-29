/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2023/08/16 13:18
 * @version :   2023/08/16 13:18
 * @link    :   https://ac.nowcoder.com/acm/contest/63602/J
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    cin >> x;
    vector<vector<int>> c(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            c[i][j] = a[i] * b[j];
    vector s(c);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + c[i][j];
    int ans = 0;
    for (int si = 1; si <= n; si++)
        for (int sj = 1; sj <= m; sj++)
            for (int ti = 1; ti <= n; ti++)
                for (int tj = 1; tj <= m; tj++) {
                    int sum = s[ti][tj] - s[ti][sj - 1] - s[si - 1][tj] + s[si - 1][sj - 1];
                    if (sum <= x) {
                        ans = max(ans, (ti - si + 1) * (tj - sj + 1));
                    }
                }
    cout << ans << '\n';
    return 0;
}