#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y, s, fa;
} que[250];
int head = 1, tail = 1;
int n, m;
int G[50][50], vis[50][50];
int dt[4][2]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int beg_x, beg_y, end_x, end_y;

void printPath(int p) {
    if (p == 0)
        return;
    printPath(que[p].fa);
    auto [x, y, s, fa] = que[p];
    G[y][x] = 2;
    cout << "(" << x << ", " << y << ")\n";
}

int main() {
    // 初始化迷宫地图
    cin >> n >> m;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            cin >> G[y][x];
    cin >> beg_x >> beg_y >> end_x >> end_y;
    // 初始化迷宫入口
    vis[beg_y][beg_x] = 1;
    que[tail++] = {beg_x, beg_y, 0, 0};
    // BFS
    bool isFind = true;
    while (head < tail) {
        auto [x, y, s, fa] = que[head++];
        if (x == end_x && y == end_y) {
            isFind = true;
            break;
        }
        for (auto [dy, dx] : dt) {
            int ny = y + dy, nx = x + dx;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (G[ny][nx] == 1 || vis[ny][nx])
                continue;
            vis[ny][nx] = 1;
            que[tail++] = {nx, ny, s + 1, head - 1};
        }
    }
    // 打印出从起点走了多少步到终点
    cout << "step : " << que[head - 1].s << '\n';
    // 倒序输出所经过的位置的坐标
    printPath(head - 1);
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            cout << G[y][x] << " \n"[x == m - 1];
    return 0;
}
