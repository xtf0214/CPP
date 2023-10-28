/** 
 * @file    :   2
 * @author  :   Tanphoon 
 * @date    :   2023/10/28 23:51
 * @version :   2023/10/28 23:51
 * @link    :   https://www.lanqiao.cn/problems/5887/learning/?contest_id=145
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << ((min(m, n) > 1 && n * m % 6 == 0) ? "Yes" : "No") << '\n';     
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}