/**
 * @file    :   10
 * @author  :   Tanphoon
 * @date    :   2023/02/18 21:14
 * @version :   2023/02/18 21:14
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<vector<bool>> ths, vis;
int way[8][2]{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
int n, m, k, l;
void printGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << G[i][j] << ' ';
        cout << '\n';
    }
}
int main() {
    cin >> n >> m >> k >> l;
    G.assign(n, vector<int>(m, -1));
    ths.assign(n, vector<bool>(m));
    vis.assign(n, vector<bool>(m));
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        ths[y][x] = true;
    }
    for (int i = 0; i < l; i++) {
        int y, x;
        cin >> y >> x;
        queue<pair<int, int>> q;
        if (vis[y][x])
            continue;
        q.push({y, x});
        vis[y][x] = 1;
        if (ths[y][x]) {
            cout << "You lose";
            return 0;
        }
        while (!q.empty()) {
            auto [cy, cx] = q.front();
            q.pop();
            int cnt = 0;
            for (auto &[ty, tx] : way) {
                int ny = cy + ty, nx = cx + tx;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[ny][nx])
                    continue;
                if (ths[ny][nx])
                    cnt++;
            }
            G[cy][cx] = cnt;
            if (cnt == 0)
                for (auto &[ty, tx] : way) {
                    int ny = cy + ty, nx = cx + tx;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[ny][nx])
                        continue;
                    vis[ny][nx] = true;
                    q.push({ny, nx});
                }
        }
        printGraph();
        if (i != l - 1)
            cout << '\n';
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (G[i][j] == -1 && ths[i][j] == 0)
                return 0;
    cout << "You win";
    return 0;
}
