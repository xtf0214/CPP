/**
 * @file    :   Codeforces Round #835 (Div. 4) B
 * @author  :   Tanphoon 
 * @date    :   2022/11/21 22:35
 * @version :   2022/11/21 22:35
 * @link    :   https://codeforces.com/contest/1760/problem/B
*/
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