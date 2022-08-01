#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int T, a, b, x;
void solve()
{
    cin >> a >> b >> x;
    if (a > b)
        swap(a, b);
    if (b - a < x)
        return void(cout << -1 << endl);
    if (a % x != 0)
        a = (a / x + 1) * x;
    if (a + x > b)
        return void(cout << -1 << endl);
    cout << a << " " << a + x << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
        solve();
    return 0;
}