// P3509 [POI2010]ZAB-Frog
// https://www.luogu.com.cn/problem/P3509
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 1; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])

ll n, k, m;
vll nxt, ans;
vll a;
void getKth(int k)
{
    int l = 1, r = k + 1;
    nxt[1] = k + 1;
    for (int i = 2; i <= n; i++)
    {
        while (r + 1 <= n && a[i] - a[l] > a[r + 1] - a[i])
            l++, r++;
        if (a[i] - a[l] < a[r] - a[i])
            nxt[i] = r;
        else
            nxt[i] = l;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;
    a = vll(n + 1);
    nxt = vll(n + 1);
    ans = vll(n + 1);
    iota(all(ans), 0); // pos初始化为当前坐标
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    getKth(k); // 尺取法获取第k近的点下标

    // // 传统倍增模板
    // // 初始化
    // vector<vll> f(n + 1, vll(__lg(m) + 2));
    // for (int i = 1; i <= n; i++)
    //     f[i][0] = nxt[i];
    // for (int t = 1; t <= __lg(m) + 1; t++)
    //     for (int i = 1; i <= n; i++)
    //         f[i][t] = f[f[i][t - 1]][t - 1];
    // // 查询
    // for (int t = 0; m; m >>= 1, t++)
    //     if (m & (1 << t))
    //     {
    //         for (int i = 1; i <= n; i++)
    //             pos[i] = f[pos[i]][t]; //从上次的位置接着跳
    //     }

    // 都什么年代了还在用传统模板，全新快速幂式模板
    vll f(all(nxt));
    for (; m; m >>= 1)
    {
        if (m & 1)
            for (int i = 1; i <= n; i++)
                ans[i] = f[ans[i]]; //从上次的位置接着跳
        vll ff(f);
        for (int i = 1; i <= n; i++)
            f[i] = ff[ff[i]]; //倍增跳
    }
    print(ans);
    return 0;
}
