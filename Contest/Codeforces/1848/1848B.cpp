/**
 * @file    :   1848B
 * @author  :   Tanphoon
 * @date    :   2023/07/17 03:49
 * @version :   2023/07/17 03:49
 * @link    :   https://codeforces.com/contest/1848/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pre(k + 1, -1);
    vector<vector<int>> d(k + 1);
    for (int i = 0; i < n; i++) {
        d[a[i]].push_back(i - pre[a[i]] - 1);
        pre[a[i]] = i;
    }
    for (int i = 1; i <= k; i++)
        d[i].push_back(n - pre[i] - 1);
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++) {
        sort(d[i].begin(), d[i].end(), greater<int>());
        int t = max(d[i][0] / 2, d[i][1]);
        ans = min(ans, t);
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