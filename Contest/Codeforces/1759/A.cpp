/** 
 * @file    :   Codeforces Round #834 (Div. 3) A
 * @author  :   Tanphoon 
 * @date    :   2022/11/18 22:35
 * @version :   2022/11/18 22:35
 * @link    :   https://codeforces.com/contest/1759/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
char s[] = {'Y', 'e', 's', 'Y', 'e'};
bool solve()
{
    string ss;
    cin >> ss;
    int st;
    for (st = 0; st < 3; st++)
        if (s[st] == ss[0])
            break;
    char *str = s + st;
    for (int i = 0; i < ss.size(); i++)
        if (ss[i] != str[i % 3])
            return false;
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
