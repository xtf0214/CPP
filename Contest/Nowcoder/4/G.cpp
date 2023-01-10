#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using Node = pair<int, pii>;
const int N = 2000 + 5, INF = 0x3f3f3f3f;
int n, m;
char G[N][N];
bool vis[N][N];
int d[N][N];
int vec[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void solve()
{
    priority_queue<Node, vector<Node>, greater<Node>> q;
    memset(d, 0x3f, sizeof(d));
    q.push({0, {0, 0}});
    d[0][0] = 0;
    while (!q.empty())
    {
        auto [cy, cx] = q.top().second;
        q.pop();
        if (vis[cy][cx])
            continue;
        vis[cy][cx] = true;
        for (auto &[ny, nx] : vec)
        {
            int ty = cy + nx, tx = cx + ny;
            if (ty < 0 || ty >= n || tx < 0 || tx >= m || G[ty][tx] == '#')
                continue;
            int cost = G[ty][tx] != '*';
            if (d[ty][tx] > d[cy][cx] + cost)
                q.push({d[ty][tx] = d[cy][cx] + cost, {ty, tx}});
        }
    }
    cout << ((d[n - 1][m - 1] == INF) ? -1 : d[n - 1][m - 1]) << endl;
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cout << d[i][j] << " \n"[j == m - 1];
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> G[i][j];
    solve();
    return 0;
}