#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e3 + 5;

int n, m, k;
int G[N][N];
int way[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[N][N];
int ans = 1e9;

void dfs(int i, int j, int cur, int t, int s) {
    if (i == n && j == m) {
        ans = min(ans, s);
        return;
    }
    //	cout << i << " " << j << " " << cur << " " << t << " " << endl;
    for (auto dt : way) {
        int ny = i + dt[0], nx = j + dt[1];
        if (1 <= ny && ny <= n && 1 <= nx && nx <= m && !vis[ny][nx]) {
            if (t == k && G[ny][nx] == cur ^ 1) {
                vis[ny][nx] = true;
                dfs(ny, nx, cur ^ 1, 1, s + 1);
                vis[ny][nx] = false;
            } else if (t != k && G[ny][nx] == cur) {
                vis[ny][nx] = true;
                dfs(ny, nx, cur, t + 1, s + 1);
                vis[ny][nx] = false;
            }
        }
    }
}
void bfs(int y, int x) {
    struct Node {
        int y, x, cur, t = 0, step = 0;
    };
    queue<Node> q;
    q.push(Node{1, 1, 0, 1, 1});
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        if (now.y == n && now.x == m) {
            ans = now.step;
            return;
        }
        for (auto dt : way) {
            int ny = now.y + dt[0], nx = now.x + dt[1];
            if (1 <= ny && ny <= n && 1 <= nx && nx <= m && !vis[ny][nx]) {
                if (now.t == k && G[ny][nx] == now.cur ^ 1) {
                    vis[ny][nx] = true;
                    q.push(Node{ny, nx, now.cur ^ 1, 1, now.step + 1});
                } else if (now.t != k && G[ny][nx] == now.cur) {
                    vis[ny][nx] = true;
                    q.push(Node{ny, nx, now.cur, now.t + 1, now.step + 1});
                }
            }
        }
    }
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            G[i][j] = c - 'A';
        }
    vis[1][1] = true;
    // dfs(1, 1, 0, 1, 1);
    bfs(1, 1);
    if (ans == 1e9) {
        cout << -1;
    } else {
        cout << ans - 1;
    }
    return 0;
}
