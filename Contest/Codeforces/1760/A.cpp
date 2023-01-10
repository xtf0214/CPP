/**
 * @file    :   Codeforces Round #835 (Div. 4) A
 * @author  :   Tanphoon 
 * @date    :   2022/11/21 22:35
 * @version :   2022/11/21 22:35
 * @link    :   https://codeforces.com/contest/1760/problem/A
*/
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