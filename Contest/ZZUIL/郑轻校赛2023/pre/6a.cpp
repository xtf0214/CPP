#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
const int maxn = (int)1e5 + 10;
const int BN = 30;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const double eps = 1e-6;
const double r = 6371009;
const double PI = acos(-1);
struct nodes {
    int x, y;
    nodes(int a = 0, int b = 0) : x(a), y(b) {}
} ser[15];
int n, m;
char ansmp[555][555], mp[555][555];
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1}, dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
bool vis[555][555];
bool check(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return true;
    else if (vis[x][y])
        return true;
    return false;
}
bool bfs(int x, int y) {
    if (mp[x][y] == '*')
        return true;
    else if (mp[x][y] >= '1' && mp[x][y] <= '8') {
        vis[x][y] = true;
        ansmp[x][y] = mp[x][y];
        return false;
    } else {
        queue<nodes> que;
        que.push(nodes(x, y));
        ansmp[x][y] = '0';
        while (!que.empty()) {
            nodes tmp = que.front();
            que.pop();
            int nx = tmp.x, ny = tmp.y;
            for (int i = 0; i < 8; i++) {
                int tx = nx + dx[i], ty = ny + dy[i];
                if (check(tx, ty))
                    continue;
                vis[tx][ty] = true;
                if (mp[tx][ty] >= '1' && mp[tx][ty] <= '8')
                    ansmp[tx][ty] = mp[tx][ty];
                else {
                    ansmp[tx][ty] = '0';
                    que.push(nodes(tx, ty));
                }
            }
        }
        return false;
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int q;
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 0; i < n; i++) {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; j++) {
                ansmp[i][j] = '.';
                vis[i][j] = 0;
            }
        }
        bool flag = true;
        int ans = 0;
        for (int i = 0; i < q; i++)
            scanf("%d%d", &ser[i].x, &ser[i].y);
        for (int i = 0; i < q; i++) {
            if (bfs(ser[i].x - 1, ser[i].y - 1)) {
                flag = false;
                ans = i + 1;
                break;
            }
        }
        if (!flag)
            printf("Game over in step %d\n", ans);
        else {
            for (int i = 0; i < n; i++)
                printf("%s\n", ansmp[i]);
        }
    }
    return 0;
}