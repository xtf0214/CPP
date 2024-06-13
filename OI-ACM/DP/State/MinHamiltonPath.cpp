/**
 * @file    :   MinHamiltonPath
 * @author  :   Tanphoon
 * @date    :   2024/06/13 16:03
 * @version :   2024/06/13 16:03
 * @link    :   https://www.acwing.com/problem/content/description/93/
 */
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
vector<vector<int>> G, dp;

void rec1() {
    dp.assign(1 << n, vector<int>(n, INF));
    dp[(1 << n) - 1][n - 1] = 0;
    for (int S = (1 << n) - 2; S >= 0; S--)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (!(S >> v & 1))
                    dp[S][u] = min(dp[S][u], dp[S | 1 << v][v] + G[u][v]);
    cout << dp[0][0] << '\n';
}
void rec2() {
    dp.assign(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;                      // 开始：集合中只有点0，起点和终点都是0
    for (int S = 1; S < (1 << n); S++) // 从小集合扩展到大集合，集合用S的二进制表示
        for (int j = 0; j < n; j++)    // 枚举点j
            if ((S >> j) & 1)          //(1): 这个判断与下面的(2)一起起作用
                for (int k = 0; k < n; k++)      // 枚举到达j的点k，k属于集合S-j
                    if ((S ^ (1 << j)) >> k & 1) //(2): k属于集合S-j。S-j用(1)保证
                        // 把(1)和(2)写在一起，像下面这样，更容易理解，但是效率低一点：
                        // if( ((S>>j) & 1) && ((S^(1<<j)) >> k & 1) )
                        dp[S][j] = min(dp[S][j], dp[S ^ (1 << j)][k] + G[k][j]);
    cout << dp[(1 << n) - 1][n - 1]; // 输出：路径包含了所有的点，终点是n-1
}
int main() {
    cin >> n;
    G.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];
    rec1();
    // rec2();
    return 0;
}
