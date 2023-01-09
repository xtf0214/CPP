/** 
 * @file    :   Codeforces Round #805 (Div. 3) A
 * @author  :   Tanphoon 
 * @date    :   2022/07/10 22:35
 * @version :   2022/07/10 22:35
 * @link    :   https://codeforces.com/contest/1702/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int T, x, res, i;
    cin >> T;
    while (T--)
    {
        cin >> x;
        res = 0;
        for (i = 1; x >= 10; x /= 10, i *= 10)
            res += x % 10 * i;
        res += (x - 1) * i;
        cout << res << endl;
    }
    return 0;
}