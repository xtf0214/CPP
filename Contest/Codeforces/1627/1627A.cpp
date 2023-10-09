/**
 * @file    :   1627A
 * @author  :   Tanphoon
 * @date    :   2023/09/15 20:50
 * @version :   2023/09/15 20:50
 * @link    :   https://codeforces.com/contest/1627/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int r, c;
    cin >> r >> c;
    r--, c--;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0, all = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            all += (s[i][j] == 'B');
    if (s[r][c] == 'B') {
        cout << 0 << '\n';
        return;
    }
    if (all == 0) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
        ans += (s[i][c] == 'B');
    for (int i = 0; i < m; i++)
        ans += (s[r][i] == 'B');
    if (ans > 0)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}