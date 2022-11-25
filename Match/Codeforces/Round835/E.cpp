#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using vT = vector<T>;
#define all(v) v.begin(), v.end()
ll n, c, d;
vT<ll> a;
vT<ll> s;
bool check(int m)
{
    ll sum = 0;
    for (int i = 0; i <= m && i < n; i++)
    {
        sum += d / (m + 1) * a[i];
        if (d % (m + 1) > i)
            sum += a[i];
    }
    return sum >= c ? true : false;
}
void solve()
{
    cin >> n >> c >> d;
    a = vT<ll>(n);
    s = vT<ll>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a), greater());
    partial_sum(all(a), s.begin());
    if (s[0] * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }
    if (s[min(d - 1, n - 1)] >= c)
    {
        cout << "Infinity" << endl;
        return;
    }
    int l = 0, r = d + 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}
signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}