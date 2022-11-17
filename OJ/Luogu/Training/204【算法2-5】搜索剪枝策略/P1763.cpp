// P1763 埃及分数
// https://www.luogu.com.cn/problem/P1763
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dep = 1, st[11], ans[11], flag;
void dfs(ll a, ll b, int x)
{
    if (x > dep)
        return;
    if (a == 1 && b > st[x - 1])
    {
        st[x] = b;
        if (!flag || st[x] < ans[x])
            for (int i = 1; i <= dep; i++)
                ans[i] = st[i];
        flag = 1;
        return;
    }
    ll l = max(b / a + 1, st[x - 1] + 1);
    ll r = (dep - x + 1) * b / a;
    if (flag && r >= ans[dep])
        r = ans[dep] - 1;
    for (ll i = l; i < r; i++)
    {
        st[x] = i;
        ll gcd = __gcd(a * i - b, b * i);
        dfs((a * i - b) / gcd, b * i / gcd, x + 1); // a/b-1/i
    }
}
signed main()
{
    ll a, b;
    cin >> a >> b;
    ll c = __gcd(a, b);
    a /= c, b /= c, st[0] = 1;
    for (dep = 1; dep <= 10; dep++)
    {
        dfs(a, b, 1);
        if (flag)
        {
            for (int i = 1; i <= dep; i++)
                printf("%lld ", ans[i]);
            break;
        }
    }
    return 0;
}