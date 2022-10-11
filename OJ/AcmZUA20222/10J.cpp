#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    ll s = 1;
    cin >> n;
    for (int i = 1; i <= n;i++)
        s *= i;
    cout << s << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}