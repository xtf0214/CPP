#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])

void solve()
{
    int n;
    cin >> n;
    vT<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(all(a));
    vT<int> ans(n);
    for (int i = 0; i < n - 1; i++)
        ans[a[i].S] = a[i].F - a[n - 1].F;
    ans[a[n - 1].S] = a[n - 1].F - a[n - 2].F;
    print(ans);
}
signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}