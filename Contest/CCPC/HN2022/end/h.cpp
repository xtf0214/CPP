#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second

int m, st, ed, flag;
int adjs[6] = {4, 1, 2, 3, 4, 1};
// the direction of next step [1:right, 2:down, 3:left, 4:up]
pii vec[5] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> G[2];
vector<bool> vis[2];

// k is the source of water [1:left, 2:up, 3:right, 4:down]
void dfs(int y, int x, int k)
{
    if (y == 2 && x == ed - 1)
        return void(flag = 1);
    if (y < 0 || y >= 2 || x < 0 || x >= m || vis[y][x])
        return;
    vis[y][x] = true;
    if (5 <= G[y][x] && G[y][x] <= 6)
        dfs(y + vec[k].fi, x + vec[k].se, k);
    else if (1 <= G[y][x] && G[y][x] <= 4)
    {
        // k1,k2 is the direction of the next step
        int k1 = adjs[k - 1], k2 = adjs[k + 1];
        dfs(y + vec[k1].fi, x + vec[k1].se, k1);
        dfs(y + vec[k2].fi, x + vec[k2].se, k2);
    }
    vis[y][x] = false;
}
void solve()
{
    char c;
    cin >> m >> st >> ed;
    G[0].resize(m, 0), G[1].resize(m, 0);
    vis[0].resize(m), vis[1].resize(m);
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j < m; j++)
            cin >> c, G[i][j] = c == 'I' ? 5 : 1;
    flag = 0;
    dfs(0, st - 1, 2);
    puts(flag ? "YES" : "NO");
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}