#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m;
int Map[5][5] =
    {
        {1, 2, 0, 3, 4},
        {0, 5, 6, 7, 0},
        {0, 8, 9, 10, 0},
        {0, 11, 12, 13, 0},
        {14, 15, 0, 16, 17}};
int key[20];
bool occupy[20];
int con[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int main()
{
    vector<int> dots[20];
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
        {
            if (Map[y][x] == 0)
                continue;
            int ty, tx;
            for (int k = 0; k < 4; k++)
            {
                ty = y + con[k][0];
                tx = x + con[k][1];
                if (tx < 0 || tx >= 5 || ty < 0 || ty >= 5 || Map[ty][tx] == 0)
                    continue;
                dots[Map[y][x]].push_back(Map[ty][tx]);
            }
        }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int i = 1; i <= 17; i++)
            cin >> key[i];
        cin >> m;
        int sum = 0;
        int now = 14;
        m -= ceil(key[14] / 6);
        occupy[14] = true;
        for (int i = 0; i < m; i++)
        {
            sum += 6;
            int min = min_element(dots[now].begin(), dots[now].end()) - dots[now].begin();
            for (int i = 0; i < dots[now].size(); i++)
            {
                int k = dots[now][i];
                if ()
            }
        }
    }
}