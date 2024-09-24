/**
 * @file    :   P3509 [POI2010]ZAB-Frog
 * @author  :   Tanphoon
 * @date    :   2024/09/24 20:37
 * @version :   2024/09/24 20:37
 * @link    :   https://www.luogu.com.cn/problem/P3509
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, m;
vector<ll> nxt, ans, a;

void getKth(int k) {
    int l = 1, r = k + 1;
    nxt[1] = k + 1;
    for (int i = 2; i <= n; i++) {
        while (r + 1 <= n && a[i] - a[l] > a[r + 1] - a[i])
            l++, r++;
        if (a[i] - a[l] < a[r] - a[i])
            nxt[i] = r;
        else
            nxt[i] = l;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;
    a = vector<ll>(n + 1);
    nxt = vector<ll>(n + 1);
    ans = vector<ll>(n + 1);
    iota(ans.begin(), ans.end(), 0); // pos初始化为当前坐标
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    getKth(k); // 尺取法获取第k近的点下标
    int logm = __lg(m);
    vector f(n + 1, vector<ll>(logm + 1));
    for (int i = 1; i <= n; i++)
        f[i][0] = nxt[i];
    for (int t = 1; t <= logm; t++)
        for (int i = 1; i <= n; i++)
            f[i][t] = f[f[i][t - 1]][t - 1];
    for (int t = logm; t >= 0; t--)
        if (m - (1 << t) >= 0) {
            for (int i = 1; i <= n; i++)
                ans[i] = f[ans[i]][t];
            m -= 1LL << t;
        }
    // vector<ll> f(nxt);
    // for (; m; m >>= 1) {
    //     if (m & 1)
    //         for (int i = 1; i <= n; i++)
    //             ans[i] = f[ans[i]]; // 从上次的位置接着跳
    //     vector<ll> ff(f);
    //     for (int i = 1; i <= n; i++)
    //         f[i] = ff[ff[i]]; // 倍增跳
    // }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}
