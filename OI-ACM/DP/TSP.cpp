// P1433 吃奶酪
// https://www.luogu.com.cn/problem/P1433
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;
template <typename T>
using vvT = vector<vector<T>>;
#define vvTy(Ty, n, m, k) vvT<Ty>(n, vT<Ty>(m, k))
#define y first
#define x second
#define bin(x) bitset<3>(x)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
string tab[6];
// #define DEBUG
int V;
vvT<double> dist, dp;
vT<int> par;
double rec(int S, int u, int st)
{
#ifdef DEBUG
    cout << tab[st] << bin(S) << u << endl;
#endif
    if (dp[S][u] >= 0)
        return dp[S][u];
    if (S == (1 << V) - 1 && u == 0)
        return dp[S][u] = 0;
    double res = INF;
    for (int v = 0; v < V; v++)
        if (!(S >> v & 1))
            res = min(res, rec(S | 1 << v, v, st + 1) + dist[u][v]);
#ifdef DEBUG
    cout << tab[st] << bin(S) << u << endl;
#endif
    return dp[S][u] = res;
}
void solve()
{
    dp = vvTy(double, 1 << V, V, INF);
    dp[(1 << V) - 1][0] = 0;
    for (int S = (1 << V) - 2; S >= 0; S--)
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; V++)
                if (!(S >> v & 1))
                {
                    dp[S][u] = min(dp[S][u], dp[S | 1 << v][v] + dist[u][v]);
                }
    cout << dp[0][0];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> V, V++;

    vT<pii> ps(V);
    par = vT<int>(V);
    dist = vvTy(double, V, V, 0);
    dp = vvTy(double, 1 << V, V, -1);
    for (int i = 1; i < 6; i++)
        tab[i] = tab[i - 1] + "    ";
    ps[0] = {0, 0};
    for (int i = 1; i < V; i++)
        cin >> ps[i].x >> ps[i].y;
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            dist[j][i] = dist[i][j] = hypot(ps[i].x - ps[j].x, ps[i].y - ps[j].y);

    cout << rec(0, 0, 0);
    return 0;
}