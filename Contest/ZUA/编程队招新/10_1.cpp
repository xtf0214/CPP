#include <bits/stdc++.h>
using namespace std;

int n, m, k, l;

vector<vector<bool>> ths; //雷的坐标
vector<vector<int>> graph;
int way[8][2] = {
    {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
void outGraph(vector<vector<int>> &graph)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    cin >> n >> m >> k >> l;
    ths = vector<vector<bool>>(n, vector<bool>(m));
    graph = vector<vector<int>>(n, vector<int>(m, -1));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> y >> x;
        ths[y][x] = 1;
        //		graph[y][x] = -2; //-2表示雷
    }

    vector<pair<int, int>> touch;
    vector<vector<bool>> vis = vector<vector<bool>>(n, vector<bool>(m));
    for (int s = 0; s < l; s++)
    {
        int i, j;
        cin >> i >> j; // i行j列
        queue<pair<int, int>> qq;
        if (vis[i][j] == 1)
            continue;
        qq.push({j, i});
        vis[i][j] = 1;
        if (ths[i][j])
        {
            //踩到地雷
            printf("You lose");
            return 0;
        }
        while (!qq.empty())
        {
            auto t = qq.front();
            qq.pop();
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
                {
                    cnt++;
                }
            }
            // 根据地雷数量决定是否将新的探测点加入队列。
            for (int k = 0; cnt == 0 && k < 8; k++)
            {
                int tx = x + way[k][0];
                int ty = y + way[k][1];
                if (tx < 0 || ty < 0 || tx >= m || ty >= n || vis[ty][tx])
                    continue;
                vis[ty][tx] = 1;
                qq.push({tx, ty});
            }
            graph[y][x] = cnt;
        }
        outGraph(graph);
        if (s != l - 1)
            printf("\n");
    }
    //如果所有未被探测的方格都是雷，说明游戏获胜，否则结束程序不输出，因为没有输掉比赛。
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == -1 && ths[i][j] == 0)
            {
                return 0;
            }
        }
    }
    printf("You win");
    return 0;
}