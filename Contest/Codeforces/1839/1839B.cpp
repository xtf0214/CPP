/**
 * @file    :   Codeforces Round 876 (Div. 2) 1839B
 * @author  :   Tanphoon
 * @date    :   2023/06/05 17:37
 * @version :   2023/06/05 17:37
 * @link    :   https://codeforces.com/contest/1839/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        a[x].push_back(y);
    }
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end(), greater<int>());
        for (int j = 0; j < min(i, (int)a[i].size()); j++)
            ans += a[i][j];
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}