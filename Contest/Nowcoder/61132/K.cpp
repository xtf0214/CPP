/** 
 * @file    :   K
 * @author  :   Tanphoon 
 * @date    :   2023/07/13 00:23
 * @version :   2023/07/13 00:23
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/K
 */
#include <bits/stdc++.h>
using namespace std;
int way[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<vector<char>> G(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> G[i][j];
    auto check = [n, m](int y, int x) { return y >= 0 && y < n && x >= 0 && x < m; };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bool ok = true;
            int cnt = 0;
            for (auto [dy, dx] : way) {
                int ny = i + dy, nx = j + dx;
                if (!check(ny, nx))
                    continue;
                if (G[ny][nx] == '1')
                    cnt++;
                if (G[ny][nx] == '2')
                    ok = false;
            }
            if (cnt == 3 && ok && G[i][j] == '0') {
                ans++;
            }
        }
    if (ans > 0) {
        cout << "YES" << '\n';
        cout << ans;
    } else {
        cout << "NO";
    }
    return 0;
}