#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

ll a[N], m;
void solve()
{
    int n;
    cin >> n;
    if (a[n] == 0)
    {
        for (int i = m; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2];
        m = n + 1;
    }
    cout << a[n] << endl;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    a[1] = a[2] = 1;
    m = 3;
    cin >> T;
    while (T--)
        solve();
    return 0;
}