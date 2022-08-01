#include <bits/stdc++.h>
using namespace std;
int n, m;
int dis[5000005];
int id(int x, int y)
{
    return x * m + y;
}
char c[5000005];
int fx[4] = {0, 0, 1, -1}, fy[4] = {1, -1, 0, 0}, w[1000];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[id(i, j)];
        }
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    for (int i = 0; i < 5000000; i++)
        dis[i] = 1e9;
    w['.'] = 1;
    w['#'] = 1e9;
    dis[id(1, 1)] = 0;
    q.push({1, 1});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = fx[i] + x;
            int ny = fy[i] + y;
            if (nx <= n && nx >= 1 && ny <= m && ny >= 1)
            {
                if (dis[id(nx, ny)] > dis[id(x, y)] + w[c[id(nx, ny)]])
                    dis[id(nx, ny)] = dis[id(x, y)] + w[c[id(nx, ny)]], q.push({nx, ny});
            }
        }
    }
    if (dis[id(n, m)] > 1e8)
        dis[id(n, m)] = -1;
    cout << dis[id(n, m)];
    return 0;
}