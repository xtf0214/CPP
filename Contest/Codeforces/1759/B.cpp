/** 
 * @file    :   Codeforces Round #834 (Div. 3) B
 * @author  :   Tanphoon 
 * @date    :   2022/11/18 22:35
 * @version :   2022/11/18 22:35
 * @link    :   https://codeforces.com/contest/1759/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vT = vector<T>;
#define all(v) v.begin(), v.end()

bool solve()
{
    int m, s, maxn = 0;
    cin >> m >> s;
    vT<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        if (maxn < a[i])
            maxn = a[i];
    }
    int s1 = (maxn + 1) * maxn / 2 - accumulate(all(a), 0);
    s -= s1;
    for (int i = maxn + 1; s > 0; i++)
        s -= i;
    if (s < 0)
        return false;
    else
        return true;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        puts(solve() ? "YES" : "NO");
    return 0;
}
