#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    stack<int> s;
    cin >> n >> m;
    vi d(n + 1), c(n + 1), next(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i] >> c[i];
    d.push_back(INF), c.push_back(INF);
    for (int i = 1; i <= n + 1; i++)
    {
        while (!s.empty() && d[s.top()] < d[i])
            next[s.top()] = i, s.pop();
        s.push(i);
    }
    vvi f(n + 2, vi(20)), g(n + 2, vi(20));
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = next[i];
        g[i][0] = c[f[i][0]];
    }
    for (int t = 1; t <= 16; t++)
        for (int i = 1; i <= n; i++)
        {
            int k = f[i][t - 1]; // 从
            f[i][t] = f[k][t - 1];
            g[i][t] = g[i][t - 1] + g[k][t - 1];
        }
    while (m--)
    {
        int r, v;
        cin >> r >> v;
        if (v > c[r])
        {
            v -= c[r];
            for (int t = 16; t >= 0; t--)
                if (v > g[r][t])
                {
                    v -= g[r][t];
                    r = f[r][t];
                }
            r = f[r][0];
        }
        if (r == n + 1)
            r = 0;
        cout << r << endl;
    }
    return 0;
}