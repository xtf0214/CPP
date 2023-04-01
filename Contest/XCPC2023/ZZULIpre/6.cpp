// #include "_DEBUG.h"
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int way[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
bool ths[N][N], vis[N][N];
int G[N][N];
int step;
int n, m, k;
void solve() {
    cin >> n >> m >> k;
    memset(ths, 0, sizeof(ths));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            G[i][j] = -1;
            if (c == '*')
                ths[i][j] = true;
        }
    for (step = 1; step <= k; step++) {
        queue<pair<int, int>> Q;
        int y, x;
        // cin >> y >> x;
        cin >> x >> y;

        if (vis[y][x])
            continue;
        if (ths[y][x]) {
            break;
        }
        Q.push({y, x});
        while (!Q.empty()) {
            auto [cy, cx] = Q.front();
            Q.pop();
            int cnt = 0;
            for (auto [y, x] : way) {
                int ny = cy + y, nx = cx + x;
                if (ny < 1 || ny > n || nx < 1 || nx > m || vis[ny][nx])
                    continue;
                if (ths[ny][nx])
                    cnt++;
            }
            G[cy][cx] = cnt;
            if (cnt == 0)
                for (auto [y, x] : way) {
                    int ny = cy + y, nx = cx + x;
                    if (ny < 1 || ny > n || nx < 1 || nx > m || vis[ny][nx])
                        continue;
                    vis[ny][nx] = true;
                    Q.push({ny, nx});
                }
        }
    }
}
void printG() {
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++) {
            if (ths[y][x] || G[y][x] == -1)
                cout << '.';
            else
                cout << G[y][x];
            if (x == m)
                cout << endl;
        }
}
int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    if (step < k + 1)
        printf("Game over in step %d", step);
    else
        printG();
    return 0;
}