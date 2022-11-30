// P3817 小A的糖果
// https://www.luogu.com.cn/problem/P3817
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
    int n, x;
    ll ans = 0;
    cin >> n >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] + a[i - 1] > x)
        {
            ans += a[i] + a[i - 1] - x;
            a[i] = x - a[i - 1];
        }
    cout << ans;
    return 0;
}