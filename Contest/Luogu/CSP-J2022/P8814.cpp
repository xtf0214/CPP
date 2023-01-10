#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, e, d, s;
    cin >> n >> d >> e;
    s = n - e * d + 2;
    ll delta = s * s - 4 * n;
    if (delta >= 0)
    {
        ll sqr_delta = floor(sqrt(delta));
        if (sqr_delta * sqr_delta == delta)
            cout << (s - sqr_delta) / 2 << " " << (s + sqr_delta) / 2 << endl;
        else
            cout << "NO" << endl;
    }
    else
        cout << "NO" << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
