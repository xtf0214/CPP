#include <bits/stdc++.h>
using namespace std;
int m, n;
struct Node
{
    int x = 0, y = 0, fill = 0, s = -1;
    bool vis = false;
    Node *f;
    void update(int _s, Node *_f) { s = _s, f = _f, vis = true; }
} maps[50][50];
int Sx, Sy, Ex, Ey;

int vec[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
queue<Node *> q;

void bfs()
{
    while (!q.empty())
    {
        Node *t = q.front();
        if (t->x == Ex && t->y == Ey)
        {
            cout << "Shortest Path = " << t->s << endl;
            for (Node *p = t; p; p = p->f)
                printf("(%d, %d)->", p->x, p->y);
            cout << endl;
            return;
        }
        for (auto v : vec)
        {
            int ny = t->y + v[1], nx = t->x + v[0];
            if (nx < 1 || nx > m || ny < 1 || ny > n || maps[ny][nx].vis || maps[ny][nx].fill == 1)
                continue;
            q.push(&maps[ny][nx]);
            maps[ny][nx].update(t->s + 1, t);
        }
        q.pop();
    }
    cout << "Not Found!" << endl;
}
int main()
{
    ifstream fin("D:\\Code\\CPP\\OI-ACM\\Graph\\input\\floodfill.in");
    fin >> n >> m;
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
        {
            fin >> maps[y][x].fill;
            maps[y][x].y = y, maps[y][x].x = x;
        }
    fin >> Sx >> Sy >> Ex >> Ey;
    q.push(&maps[Sy][Sx]);
    maps[Sy][Sx].update(0, NULL);
    bfs();
    return 0;
}
