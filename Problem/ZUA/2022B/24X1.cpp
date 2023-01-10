// 1040 Problem  X	n皇后问题（第五讲）
#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;

int cnt;
//第k列，第k副对角线，第k主对角线是否有皇后
bool vis[3][N];
// c[i]为第i行皇后所在的列vis[0]
int c[N];

// 第k行的皇后
void dfs(int k, int n)
{
    if (k == n)
        return void(++cnt);
    // 搜索第i列
    for (int i = 0; i < n; i++)
        if (!vis[0][i] && !vis[1][k + i] && !vis[2][k - i + n])
        {
            c[k] = i;
            vis[0][i] = vis[1][k + i] = vis[2][k - i + n] = true;
            dfs(k + 1, n);
            vis[0][i] = vis[1][k + i] = vis[2][k - i + n] = false;
        }
}
int main()
{
    int n;
    while (cin >> n)
    {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        dfs(0, n);
        cout << cnt << endl;
    }
    return 0;
}