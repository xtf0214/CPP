#include <bits/stdc++.h>
using namespace std;
int m, n;
struct Map
{
    int fill = 0;
    bool vis = false;
} maps[50][50];
int Sx, Sy, Ex, Ey;

int vec[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
struct Node
{
    int x, y, s;
};
queue<Node> q;

void bfs()
{
    while (!q.empty())
    {
        Node t = q.front();
        q.pop();
        if (t.x == Ex && t.y == Ey)
        {
            cout << "Shortest Path = " << t.s << endl;
            return;
        }
        for (auto v : vec)
        {
            int ny = t.y + v[1], nx = t.x + v[0];
            if (nx < 1 || nx > m || ny < 1 || ny > n || maps[ny][nx].vis || maps[ny][nx].fill == 1)
                continue;
            q.push({nx, ny, t.s + 1});
            maps[ny][nx].vis = true;
        }
    }
    cout << "Not Found!" << endl;
}
int main()
{
    ifstream fin("D:\\Code\\CPP\\OI-ACM\\Graph\\input\\floodfill.in");
    fin >> n >> m;
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
            fin >> maps[y][x].fill;
    fin >> Sx >> Sy >> Ex >> Ey;
    q.push({Sx, Sy, 0});
    maps[Sy][Sx].vis = true;
    bfs();
    return 0;
}
