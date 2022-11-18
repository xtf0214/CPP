// P1379 八数码难题
// https://www.luogu.com.cn/problem/P1379
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; // →↑←↓
int bg, ed = 123804765;
int a[9];
int (*b)[3] = (int (*)[3])a;
map<int, int> rec[2]; //两个map分别记录从源点和终点出发的步数
queue<pair<int, bool>> Q;

int change(int u, int op)
{
    int cy, cx, ny, nx;
    for (int i = 8; i >= 0; i--, u /= 10)
    {
        a[i] = u % 10;
        if (a[i] == 0)
            cy = i / 3, cx = i % 3;
    }
    ny = cy + vec[op][0];
    nx = cx + vec[op][1];
    if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
        return -1;
    swap(b[cy][cx], b[ny][nx]);
    int v = 0;
    for (int i = 0; i < 9; i++)
        v = v * 10 + a[i];
    return v;
}
void check(int v, pair<int, bool> h)
{
    if (auto &[u, fa] = h; v != -1)
    {
        if (rec[fa ^ 1].count(v))
        {
            cout << rec[0][v] + rec[1][u] + 1;
            exit(0);
        }
        else
        {
            rec[fa][v] = rec[fa][u] + 1;
            Q.push({v, fa});
        }
    }
}
signed main()
{
    cin >> bg;
    if (bg == ed)
    {
        puts("0");
        return 0;
    }
    Q.push({bg, 0});
    Q.push({ed, 1});
    while (!Q.empty())
    {
        auto h = Q.front();
        Q.pop();
        int v;
        for (int i = 0; i < 4; i++)
        {
            v = change(h.first, i);
            check(v, h);
        }
    }
    return 0;
}