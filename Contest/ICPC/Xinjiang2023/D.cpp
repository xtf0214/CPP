/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2024/01/23 19:07
 * @version :   2024/02/01 14:48
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/D
 */
#include <bits/stdc++.h>
using namespace std;
const int dt[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
inline void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n, vector<int>(m));
    vector s(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> G[i][j];
    function<void(int, int, int)> dfs = [&](int y, int x, int d) {
        if (s[y][x] >= d) // 二次更新路线，从小到大方向走
            return;
        s[y][x] = d;
        for (auto &[dy, dx] : dt) {
            int ny = y + dy, nx = x + dx;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (G[ny][nx] == G[y][x]) 
                dfs(ny, nx, d);
            else if (G[ny][nx] > G[y][x]) 
                dfs(ny, nx, d + 1);
            
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs(i, j, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, s[i][j]);
    cout << ans << '\n';
}
/*
1
2 3
12 20 30
1 20 24 */
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}