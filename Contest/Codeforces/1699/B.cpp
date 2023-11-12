/** 
 * @file    :   B
 * @author  :   Tanphoon 
 * @date    :   2023/11/07 00:09
 * @version :   2023/11/07 00:09
 * @link    :   https://codeforces.com/contest/1699/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cout << ((i % 4 == j % 4) || (i % 4 + j % 4 == 3)) << " \n"[j == m - 1];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}