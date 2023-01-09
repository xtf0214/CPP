/** 
 * @file    :   Codeforces Round #805 (Div. 3) C
 * @author  :   Tanphoon 
 * @date    :   2022/07/10 22:35
 * @version :   2022/07/10 22:35
 * @link    :   https://codeforces.com/contest/1702/problem/C
*/
#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, k, u, v;
    map<int, int> a, b;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> u;
            if (!a.count(u))
                a[u] = i;
            b[u] = i;
        }
        while (k--)
        {
            cin >> u >> v;
            if (a.count(u) && a.count(v) && a[u] < b[v])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        a.clear();
        b.clear();
    }
    return 0;
}