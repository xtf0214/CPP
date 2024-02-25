/**
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2024/01/22 15:40
 * @version :   2024/01/22 15:40
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/F
 */
#include <bits/stdc++.h>
using namespace std;

int calc(vector<char> ls) {
    int mn = 1e9;
    for (char p = 'a'; p <= 'z'; p++) {
        int cnt = 0;
        for (char c : ls)
            cnt += min(abs(p - c), 26 - abs(p - c));
        mn = min(mn, cnt);
    }
    return mn;
}
inline void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> G[i][j];
    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 1; j <= m / 2; j++) {
            char &a = G[i][j];
            char &b = G[i][m + 1 - j];
            char &c = G[n + 1 - i][j];
            char &d = G[n + 1 - i][m + 1 - j];
            ans += calc({a, b, c, d});
        }
    }
    if (n & 1) {
        for (int j = 1; j <= m / 2; j++)
            ans += calc({G[(n + 1) / 2][j], G[(n + 1) / 2][m + 1 - j]});
    }
    if (m & 1) {
        for (int i = 1; i <= n / 2; i++)
            ans += calc({G[i][(m + 1) / 2], G[n + 1 - i][(m + 1) / 2]});
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}