/** 
 * @file    :   Educational Codeforces Round 139 (Rated for Div. 2) A
 * @author  :   Tanphoon 
 * @date    :   2022/12/12 22:35
 * @version :   2022/12/12 22:35
 * @link    :   https://codeforces.com/contest/1766/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    for (int k = 1; k <= 1000000; k *= 10)
        for (int i = 1; i <= 9; i++)
            if (k * i <= n)
                res++;
            else {
                cout << res << endl;
                return;
            }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}