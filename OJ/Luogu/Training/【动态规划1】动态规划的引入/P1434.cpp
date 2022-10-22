// P1434 [SHOI2002] 滑雪
// https://www.luogu.com.cn/problem/P1434
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e2 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int s[N][N], a[N][N], n, m, ans = 0;
int dfs(int y, int x)
{
    if (s[y][x])
        return s[y][x];
    s[y][x] = 1;
    for (auto &[ny, nx] : vec)
    {
        int ty = y + ny, tx = x + nx;
        if (ty <= 0 || ty > n || tx <= 0 || tx > m || a[y][x] <= a[ty][tx])
            continue;
        dfs(ty, tx);
        s[y][x] = max(s[y][x], s[ty][tx] + 1);
    }
    return s[y][x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}