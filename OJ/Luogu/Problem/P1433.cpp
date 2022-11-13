// P1433 吃奶酪
// https://www.luogu.com.cn/problem/P1433
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pdd = pair<double, double>;
template <typename T>
using vT = vector<T>;
template <typename T>
using vvT = vector<vector<T>>;
#define vvTy(Ty, n, m, k) vvT<Ty>(n, vT<Ty>(m, k))
#define y first
#define x second
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n;
vT<pdd> ps;
vT<bool> vis;
vvT<double> dist;
double ans;
// O(∑i!)
void dfs(int deep, int st, double sum)
{
    if (deep > n)
        return void(ans = min(ans, sum));
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            double t = sum + dist[st][i];
            if (t >= ans)
                continue;
            vis[i] = 1;
            dfs(deep + 1, i, t);
            vis[i] = 0;
        }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    ps = vT<pdd>(n + 1);
    vis = vT<bool>(n + 1);
    dist = vvTy(double, n + 1, n + 1, 0);
    ans = INF;
    ps[0] = {0, 0};
    for (int i = 1; i <= n; i++)
        cin >> ps[i].x >> ps[i].y;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            dist[i][j] = dist[j][i] = hypot(ps[i].x - ps[j].x, ps[i].y - ps[j].y);
    dfs(1, 0, 0);
    printf("%.2lf", ans);
    return 0;
}