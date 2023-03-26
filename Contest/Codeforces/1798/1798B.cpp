/**
 * @file    :   1798B
 * @author  :   Tanphoon
 * @date    :   2023/03/26 23:29
 * @version :   2023/03/26 23:29
 * @link    :   https://codeforces.com/contest/1798/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    vector<int> last(50005), ans(m, -1); // 中奖的人之后不能买彩票了，第i天中奖的人是最后一次买彩票的人
    for (int i = 0, sz; i < m; i++) {
        cin >> sz;
        for (int j = 0, x; j < sz; j++) {
            cin >> x;
            a[i].push_back(x);
            last[x] = i;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int x : a[i])
            if (last[x] == i) {
                ans[i] = x;
                break;
            }
        if (ans[i] == -1) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << " \n"[i + 1 == m];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}