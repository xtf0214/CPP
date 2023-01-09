/** 
 * @file    :   Educational Codeforces Round 132 (Rated for Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/07/21 22:35
 * @version :   2022/07/21 22:35
 * @link    :   https://codeforces.com/contest/1709/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int T;
    int x, a[4];
    cin >> T;
    while (T--)
    {
        cin >> x >> a[1] >> a[2] >> a[3];
        if (a[x] == 0 || a[a[x]] == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}