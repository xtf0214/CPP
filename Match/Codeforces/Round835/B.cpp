#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    char c1, c2;
    while (n--)
    {
        cin >> c1;
        c2 = max(c1, c2);
    }
    cout << c2 - 'a' + 1 << endl;
}
signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}