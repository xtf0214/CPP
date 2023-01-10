/** 
 * @file    :   Educational Codeforces Round 133 (Rated for Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/08/04 22:35
 * @version :   2022/08/04 22:35
 * @link    :   https://codeforces.com/contest/1716/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int r[13]{0, 2, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n % 6 == 0)
            cout << n / 6 * r[6] << endl;
        else if (n < 12)
            cout << r[n] << endl;
        else
            cout << (n - 6) / 6 * r[6] + r[n % 6 + 6] << endl;
    }
    return 0;
}
