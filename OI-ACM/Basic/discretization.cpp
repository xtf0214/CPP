#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvi = vector<vi>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int n, w, h;
vpii ax, ay;
vvi f;
vi dx, dy;
void compress(vpii &a, vi &d, int n)
{
    for (auto &v : a)
        for (int b = -1; b <= 1; b++) // 相邻的两个分隔
        {
            int t1 = v.fi + b, t2 = v.se + b;
            if (1 <= t1 && t1 <= n)
                d.push_back(t1);
            if (1 <= t2 && t2 <= n)
                d.push_back(t2);
        }
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    map<int, int> Map;
    for (int i = 0; i < d.size(); i++)
        Map[d[i]] = i;
    for (auto &v : a)
        v.fi = Map[v.fi], v.se = Map[v.se];
}
void bfs(int y, int x)
{
    queue<pii> q;
    q.push({y, x});
    while (!q.empty())
    {
        auto [sy, sx] = q.front();
        q.pop();
        f[sy][sx] = 1;
        for (auto &[ny, nx] : vec)
        {
            int ty = sy + ny, tx = sx + nx;
            if (ty < 0 || ty >= h || tx < 0 || tx >= w || f[ty][tx])
                continue;
            q.push({ty, tx});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> h >> w;
    ax = vpii(n), ay = vpii(n);
    for (int i = 0; i < n; i++)
        cin >> ax[i].fi >> ax[i].se >> ay[i].fi >> ay[i].se;
    compress(ay, dy, h);
    compress(ax, dx, w);
    h = dy.size(), w = dx.size();
    f = vvi(h, vi(w));
    for (int i = 0; i < n; i++)
        for (int j = ay[i].fi; j <= ay[i].se; j++)
            for (int k = ax[i].fi; k <= ax[i].se; k++)
                f[j][k] = 1;
    for (int i = 0; i < h; i++, cout << endl)
        for (int j = 0; j < w; j++)
            cout << (f[i][j] ? "[]" : "  ");
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            if (f[i][j])
                continue;
            bfs(i, j);
            // for (int i = 0; i < h; i++, cout << endl)
            //     for (int j = 0; j < w; j++)
            //         cout << (f[i][j] ? "[]" : "  ");
            // cout << endl;
            ans++;
        }
    cout << ans << endl;
    return 0;
}
/*
5 10 10
1 6 4 4
1 10 8 8
4 4 1 10
9 9 1 5
10 10 6 10 */