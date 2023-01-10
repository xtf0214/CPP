// CF525E
// https://www.luogu.com.cn/problem/CF525E
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;

int n, k, m;
ll S, ans;
vT<ll> a;
vT<int> b;
map<pair<int, ll>, int> f;
map<pair<int, ll>, ll> g;

ll fact(ll x)
{
    ll res;
    for (res = 1; x; res *= x--)
        if ((S / res) < x)
            return -1;
    return res;
}
void check1()
{
    int cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= m; i++)
        if (b[i] == 1)
            sum += a[i];
        else if (b[i] == 2)
        {
            ll s = fact(a[i]);
            if (s == -1 || ++cnt > k || s + sum > S)
                return;
            sum += s;
        }
    ++f[{cnt, sum}];
    ++f[{-1, sum}];
}
void dfs1(int u)
{
    if (u > m)
        check1();
    else
        for (int i = 0; i < 3; i++)
        {
            b[u] = i;
            dfs1(u + 1);
        }
}

ll query(int x, ll s)
{
    if (g.count({x, s}))
        return g[{x, s}];
    return g[{x, s}] = f[{x, s}] + (x ? query(x - 1, s) : 0);
}
void check2()
{
    int cnt = 0;
    ll sum = 0;
    for (int i = m + 1; i <= n; i++)
        if (b[i] == 1)
            sum += a[i];
        else if (b[i] == 2)
        {
            ll s = fact(a[i]);
            if (s == -1 || ++cnt > k || s + sum > S)
                return;
            sum += s;
        }
    if (f.count({-1, S - sum}))
        ans += query(k - cnt, S - sum);
}
void dfs2(int u)
{
    if (u > n)
        check2();
    else
        for (int i = 0; i < 3; i++)
        {
            b[u] = i;
            dfs2(u + 1);
        }
}
signed main()
{
    cin >> n >> k >> S;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    m = n >> 1;
    dfs1(1);
    dfs2(m + 1);
    cout << ans;
    return 0;
}