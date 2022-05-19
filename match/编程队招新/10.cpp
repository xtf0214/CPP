#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k, l;
int way[8][2] = {
    {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
vector<vector<int>> map(n, vector<int>(m, -1));
vector<vector<bool>> vis(n, vector<bool>(m, -1));
void printMap()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
            cout << map[y][x] << " ";
        cout << endl;
    }
}
int main()
{
    cin >> n >> m >> k >> l;
    for (int i = 0, y, x; i < k; i++)
    {
        cin >> y >> x;
        map[y][x] = -2;
    }
    for (int i = 0, inx, iny; i < l; i++)
    {
        cin >> iny >> inx;
        if (map[iny][inx] == -2)
        {
            printf("You lose");
            return 0;
        }
        queue<pair<int, int>> que;
        while (!que.empty())
        {
            auto now = que.front();
            que.pop();
            int x = now.first;
            int y = now.second;
            int cnt = 0;
            for (int k = 0; k < 8; k++)
            {
                int tx = x + way[k][0];
                int ty = y + way[k][1];
                if (tx < 0 || ty < 0 || tx >= m || ty >= n || vis[ty][tx])
                    continue;
                if (map[ty][tx] == -2)
                    cnt++;
            }
        }
    }
}