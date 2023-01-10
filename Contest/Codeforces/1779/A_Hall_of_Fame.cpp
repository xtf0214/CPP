/** 
 * @file    :   A_Hall_of_Fame
 * @author  :   Tanphoon 
 * @date    :   2023/01/10 04:19
 * @version :   2023/01/10 04:19
 * @link    :   https://codeforces.com/contest/1779/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    int n;
    cin >> n >> s;
    int l = -INF, r = INF;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L')
            l = max(l, i);
        else
            r = min(r, i);
    if (r - l == 1)
        cout << r << endl;
    else if (r - l < 1)
        cout << 0 << endl;
    else
        cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
