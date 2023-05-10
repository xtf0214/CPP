/**
 * @author  :   Tanphoon
 * @date    :   2023/03/30 14:27
 * @version :   2023/03/30 14:27
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y;
};
queue<node> q;
int n, a[101][101], dp[101][101];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }

int main() {
    while (cin >> n) {
        int x1, y1, x2, y2;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j] == -1)
                    x1 = i, y1 = j;
                else if (a[i][j] == -2)
                    x2 = i, y2 = j;
            }
        q.push({x1, y1});
        memset(dp, 0x3f, sizeof(dp));
        dp[x1][y1] = 0;
        while (q.size()) {
            int x = q.front().x, y = q.front().y;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!check(nx, ny) || (nx == x1 && ny == y1))
                    continue;
                if (a[nx][ny] == -2)
                    dp[nx][ny] = min(dp[nx][ny], dp[x][y]);
                else if (dp[nx][ny] > dp[x][y] + a[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + a[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
        printf("%d\n", dp[x2][y2]);
    }

    return 0;
}