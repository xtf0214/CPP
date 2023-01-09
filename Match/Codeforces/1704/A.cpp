/** 
 * @file    :   CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!) A
 * @author  :   Tanphoon 
 * @date    :   2022/07/31 22:35
 * @version :   2022/07/31 22:35
 * @link    :   https://codeforces.com/contest/1704/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if (find(a.begin(), a.end(), b[0]) == a.end())
        return void(cout << "NO\n");
    else
    {
        int loc = find(a.begin(), a.end(), b[0]) - a.begin();
        b = b.substr(1);
        a = a.substr(loc + 1);

        // 如果末尾能够匹配
        if (a.length() >= b.length() && a.substr(a.length() - b.length()) == b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}