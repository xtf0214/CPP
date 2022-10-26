#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int Map[MAX][MAX];
bool vis[MAX][MAX];
struct Node
{
    int x, y, s;
};
int vec[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int Xs, Ys, Xe, Ye;
int n, m;
void init()
{
    char c;
    cin >> n >> m;
    cin >> Xs >> Ys >> Xe >> Ye;
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
        {
            scanf(" %c", &c);
            Map[y][x] = (c == '.') ? 0 : 1;
        }
}
void bfs()
{
    queue<Node> que;
    que.push({Xs, Ys, 0});
    vis[Ys][Xs] = true;
    while (!que.empty())
    {
        Node t = que.front();
        que.pop();
        if (t.y == Ye && t.x == Xe)
        {
            cout << t.s * 100;
            return;
        }
        int tx, ty;
        for (auto i : vec)
        {
            ty = t.y + i[0];
            tx = t.x + i[1];
            if (ty <= 0 || ty <= 0 || tx > m || ty > n || vis[ty][tx] || Map[ty][tx])
                continue;
            que.push({tx, ty, t.s + 1});
            vis[ty][tx] = true;
        }
    }
    cout << -1;
}
int main()
{
    init();
    bfs();
    return 0;
}