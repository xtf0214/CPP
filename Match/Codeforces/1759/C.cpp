/** 
 * @file    :   Codeforces Round #834 (Div. 3) C
 * @author  :   Tanphoon 
 * @date    :   2022/11/18 22:35
 * @version :   2022/11/18 22:35
 * @link    :   https://codeforces.com/contest/1759/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve()
{
    ll l, x, r, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a == b)
        return 0;
    if (a > b)
        swap(a, b);
    if (b - a >= x)
        return 1;
    else if (a - l >= x || r - b >= x)
        return 2;
    else if (r - a >= x && b - l >= x)
        return 3;
    else
        return -1;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << "\n";
    return 0;
}
