// P1433 吃奶酪
// https://www.luogu.com.cn/problem/P1433
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pdd = pair<double, double>;
#define y first
#define x second
const int INF = 0x3f3f3f3f;
int V;
vector<vector<double>> dist, dp;
double rec(int S, int u) {
    if (dp[S][u] >= 0)
        return dp[S][u];
    if (S == (1 << V) - 1)
        return dp[S][u] = 0;
    double res = INF;
    for (int v = 0; v < V; v++)
        if (!(S >> v & 1))
            res = min(res, rec(S | 1 << v, v) + dist[u][v]);
    return dp[S][u] = res;
}
void solve() {
    dp.assign(1 << V, vector<double>(V, INF));
    for (int i = 0; i < V; i++)
        dp[(1 << V) - 1][i] = 0;
    for (int S = (1 << V) - 2; S >= 0; S--)
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++)
                if (!(S >> v & 1))
                    dp[S][u] = min(dp[S][u], dp[S | 1 << v][v] + dist[u][v]);
    printf("%.2lf\n", dp[0][0]);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> V, V++;
    vector<pdd> ps(V);
    dist.assign(V, vector<double>(V, 0));
    dp.assign(1 << V, vector<double>(V, -1));
    ps[0] = {0, 0};
    for (int i = 1; i < V; i++)
        cin >> ps[i].x >> ps[i].y;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            dist[i][j] = dist[j][i] = hypot(ps[i].x - ps[j].x, ps[i].y - ps[j].y);
    printf("%.2lf\n", rec(0, 0));
    return 0;
}