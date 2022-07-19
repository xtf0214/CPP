#include <bits/stdc++.h>
using namespace std;
const int MAXN = 51;
int G[MAXN][MAXN] = {0};
int d1 = 3, d2 = 6;
int vec[4][2] = {{d1, d2}, {d1, -d2}, {-d1, -d2}, {-d1, d2}};
bool layer[100];
int tx, ty;
struct Node
{
    int x, y;
    int st;
};
inline void print()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            cout << (G[i][j] ? "  " : "[]") << "\n"[j != MAXN - 1];
    cout << endl;
}
int main()
{
    queue<Node> q;
    q.push({MAXN / 2, MAXN / 2, 0});
    while (!q.empty())
    {
        Node t = q.front();
        q.pop();
        if (!layer[t.st])
        {
            print();
            layer[t.st] = true;
            cin.get();
        }
        G[t.y][t.x] = 1;
        for (int i = 0; i < 2; i++)
            for (auto v : vec)
            {
                tx = t.x + v[i];
                ty = t.y + v[i ^ 1];
                if (tx < 0 || tx >= MAXN || ty < 0 || ty >= MAXN || G[ty][tx] == 1)
                    continue;
                q.push({ty, tx, t.st + 1});
            }
    }
    print();
    return 0;
}