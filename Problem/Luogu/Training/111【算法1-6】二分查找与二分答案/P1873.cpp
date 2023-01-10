// P1873 砍树
// https://www.luogu.com.cn/problem/P1873
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using vT = vector<T>;
#define all(v) v.begin(), v.end()

vT<ll> a;
ll m, n, ans;
bool check(int h)
{
    ll tot = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > h)
            tot += a[i] - h;
    return tot >= m;
}
signed main()
{
    cin >> n >> m;
    a = vT<ll>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = 1e9, mid = (l + r) / 2;
    for (; r - l > 1; mid = (l + r) / 2)
        if (check(mid))
            l = mid;
        else
            r = mid;
    cout << l;
    return 0;
}