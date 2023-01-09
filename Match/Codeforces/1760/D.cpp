/**
 * @file    :   Codeforces Round #835 (Div. 4) D
 * @author  :   Tanphoon 
 * @date    :   2022/11/21 22:35
 * @version :   2022/11/21 22:35
 * @link    :   https://codeforces.com/contest/1760/problem/D
*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vT = vector<T>;

void solve()
{
    int n;
    cin >> n;
    vT<int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = a[n + 1] = INT_MAX;
    int l = 0;
    int ans = 0;
    for (int r = 1; r <= n; ++r)
    {
        if (a[l] != a[r])
            l = r;
        if (a[l - 1] > a[l] && a[r] < a[r + 1])
            ans++;
    }
    if (ans == 1)
        puts("YES");
    else
        puts("NO");
}
signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}