#include <bits/stdc++.h>
using namespace std;
int n, m, k, l;
vector<vector<bool>> ths;
vector<vector<int>> graph;
vector<vector<bool>> vis;
int way[8][2] = {
    {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
void outGraph()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
            printf("%d ", graph[y][x]);
        printf("\n");
    }
}
int main()
{
    cin >> n >> m >> k >> l;
    ths = vector<vector<bool>>(n, vector<bool>(m));
    graph = vector<vector<int>>(n, vector<int>(m, -1));
    vis = vector<vector<bool>>(n, vector<bool>(m));
    for (int i = 0, x, y; i < k; i++)
    {
        cin >> y >> x;
        ths[y][x] = 1;
    }
    for (int i = 0, y, x; i < l; i++)
    {
        cin >> y >> x;
        if (vis[y][x] == 1)
            continue;
        if (ths[y][x])
        {
            //踩到地雷
            printf("You lose");
            return 0;
        }
        queue<pair<int, int>> que;
        que.push({y, x});
        vis[y][x] = 1;
        
        while (!que.empty())
        {
            auto t = que.front();
            que.pop();
            int x = t.first;
            int y = t.second;
            int cnt = 0;
            //先探测地雷数量
            for (int k = 0; k < 8; k++)
            {
                int tx = x + way[k][0];
                int ty = y + way[k][1];
                if (tx < 0 || ty < 0 || tx >= m || ty >= n || vis[ty][tx])
                    continue;
                if (ths[ty][tx])
                    cnt++;
            }
            // 根据地雷数量决定是否将新的探测点加入队列。
            for (int k = 0; cnt == 0 && k < 8; k++)
            {
                int tx = x + way[k][0];
                int ty = y + way[k][1];
                if (tx < 0 || ty < 0 || tx >= m || ty >= n || vis[ty][tx])
                    continue;
                vis[ty][tx] = 1;
                que.push({ty, tx});
            }
            graph[y][x] = cnt;
        }
        outGraph();
        if (i != l - 1)
            printf("\n");
    }
    //如果所有未被探测的方格都是雷，说明游戏获胜，否则结束程序不输出，因为没有输掉比赛。
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == -1 && ths[i][j] == 0)
                return 0;
        }
    printf("You win");
    return 0;
}