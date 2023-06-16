/**
 * @file    :   G 迷宫
 * @author  :   Tanphoon
 * @date    :   2023/06/16 20:54
 * @version :   2023/06/16 20:54
 * @link    :   https://ac.nowcoder.com/acm/contest/38487/G
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

struct Node {
    int y, x, w;
    friend bool operator<(const Node &a, const Node &b) { return a.w > b.w; } // 小根堆大于号
};

int n, m;
char G[N][N];
bool vis[N][N];
int way[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs() {
    priority_queue<Node> q;
    q.push({1, 1, 0});
    vis[1][1] = true;
    while (!q.empty()) {
        auto [y, x, w] = q.top();
        q.pop();
        if (y == n && x == m)
            return w;
        for (auto &[ty, tx] : way) {
            int ny = y + ty, nx = x + tx;
            if (ny < 1 || ny > n || nx < 1 || nx > m || vis[ny][nx] || G[ny][nx] == '#')
                continue;
            vis[ny][nx] = true;
            if (G[ny][nx] == '*')
                q.push({ny, nx, w});
            else
                q.push({ny, nx, w + 1});
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> G[i][j];
    cout << bfs() << '\n';
    return 0;
}