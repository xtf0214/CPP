/** 
 * @file    :   1845B
 * @author  :   Tanphoon 
 * @date    :   2023/06/30 01:25
 * @version :   2023/06/30 01:25
 * @link    :   https://codeforces.com/contest/1845/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int y[3], x[3];
    for (int i = 0; i < 3; i++)
        cin >> y[i] >> x[i];
    int ans = 0;

    for (auto t : {x, y}) {
        if (t[0] < min(t[1], t[2]))
            ans += min(t[1], t[2]) - t[0];
        else if (t[0] > max(t[1], t[2]))
            ans += t[0] - max(t[1], t[2]);
    }
    cout << ans + 1 << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}