/** 
 * @file    :   L2-4 寻宝图
 * @author  :   Tanphoon 
 * @date    :   2023/04/24 12:15
 * @version :   2023/04/24 12:15
 * @link    :   
 */
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m;
vector<vector<char>> G;
vector<vector<int>> vis;
int way[4][2]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int treasure;
void bfs(int y, int x) {
    queue<pii> q;
    q.push({y, x});
    bool OK = false;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        if (vis[y][x])
            continue;
        vis[y][x] = true;
        if (G[y][x] > '1')
            OK = true;
        for (auto &[ty, tx] : way) {
            int ny = y + ty, nx = x + tx;
            if (ny < 1 || ny > n || nx < 1 || nx > m || G[ny][nx] == '0')
                continue;
            q.push({ny, nx});
        }
    }
    if (OK)
        treasure++;
}

int main() {
    cin >> n >> m;
    int ans = 0;
    G.assign(n + 1, vector<char>(m + 1, 0));
    vis.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> G[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && G[i][j] != '0') {
                bfs(i, j);
                ans++;
            }
        }
    cout << ans << " " << treasure;
}
