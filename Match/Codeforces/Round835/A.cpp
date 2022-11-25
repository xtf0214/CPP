#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << a[1] << endl;
}
signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}