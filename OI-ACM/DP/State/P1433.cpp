/** 
 * @file    :   P1433 吃奶酪
 * @author  :   Tanphoon
 * @date    :   2024/06/07 23:33
 * @version :   2024/06/07 23:33
 * @link    :   https://www.luogu.com.cn/problem/P1433
 */
#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;
#define y first
#define x second
const int INF = 1e9;
int n;
vector<vector<double>> G, dp;
double rec(int S, int u) {
    if (dp[S][u] >= 0)
        return dp[S][u];
    if (S == (1 << n) - 1)
        return dp[S][u] = 0;
    double res = INF;
    for (int v = 0; v < n; v++)
        if (!(S >> v & 1))
            res = min(res, rec(S | 1 << v, v) + G[u][v]);
    return dp[S][u] = res;
}
void solve() {
    dp.assign(1 << n, vector<double>(n, INF));
    for (int i = 0; i < n; i++)
        dp[(1 << n) - 1][i] = 0;
    for (int S = (1 << n) - 2; S >= 0; S--)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (!(S >> v & 1))
                    dp[S][u] = min(dp[S][u], dp[S | 1 << v][v] + G[u][v]);
    printf("%.2lf\n", dp[0][0]);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n, n++;
    vector<pdd> points(n);
    G.assign(n, vector<double>(n, 0));
    dp.assign(1 << n, vector<double>(n, -1));
    points[0] = {0, 0};
    for (int i = 1; i < n; i++)
        cin >> points[i].x >> points[i].y;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            G[i][j] = G[j][i] = hypot(points[i].x - points[j].x, points[i].y - points[j].y);
    printf("%.2lf\n", rec(0, 0));
    return 0;
}