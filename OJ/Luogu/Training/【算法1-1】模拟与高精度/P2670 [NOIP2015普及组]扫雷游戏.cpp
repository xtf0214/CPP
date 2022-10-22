#include <iostream>
using namespace std;
int m, n;
bool OverEdge(int x, int y)
{
    if (x < 1 || x > m || y < 1 || y > n)
        return true;
    else
        return false;
}
int main()
{
    char Map[101][101];
    int N[101][101] = {0};
    cin >> n >> m;
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
            cin >> Map[y][x];
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
            if (Map[y][x] == '*')
            {
                N[y][x] = -1; //标记雷
                for (int ty = -1; ty <= 1; ty++)
                    for (int tx = -1; tx <= 1; tx++)
                    {
                        if (ty == 0 && tx == 0)
                            continue; // 3*3-1=8个方向
                        if (!OverEdge(x + tx, y + ty))
                            if (Map[y + ty][x + tx] != '*') //非雷的格子计数
                                N[y + ty][x + tx]++;
                    }
            }
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (N[y][x] == -1)
                cout << '*';
            else
                cout << N[y][x];
        }
        cout << endl;
    }
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
            (N[y][x] == -1 ? (cout << '*') : (cout << N[y][x])), cout << "\n"[x != m];
    return 0;
}