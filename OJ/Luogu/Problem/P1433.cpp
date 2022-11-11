// P1433 吃奶酪
// https://www.luogu.com.cn/problem/P1433
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
#define y first
#define x second
#define all(v) v.begin(), v.end()
#define lowbit(x) x &(-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int n;
vpii ps;
vector<bool> vis;
vector<vector<double>> dist;
double ans;
// O(∑i!)
void dfs(int deep, int st, double sum)
{
    if (deep > n)
        return void(ans = max(ans, sum));
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
    ps = vpii(n + 1);
    vis = vector<bool>(n + 1);
    dist.assign(n + 1, vector<double>(n + 1, 0));
    ps[0] = {0, 0};
    for (int i = 1; i <= n; i++)
        cin >> ps[i].x >> ps[i].y;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dist[i][j] = hypot(ps[i].x - ps[j].x, ps[i].y - ps[j].y);
    dfs(1, 0, 0);
    return 0;
}