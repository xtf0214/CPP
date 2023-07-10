/**
 * @file    :   1517B
 * @author  :   Tanphoon
 * @date    :   2023/07/09 21:30
 * @version :   2023/07/09 21:30
 * @link    :   https://codeforces.com/contest/1517/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            b.emplace_back(x, i);
        }
    sort(b.begin(), b.end(), [](const auto &x, const auto &y) { return x.first < y.first; });
    for (int k = m; k < b.size(); k++) {
        auto [x, i] = b[k];
        a[i].push_back(x);
    }
    for (int k = 0; k < m; k++) {
        auto [x, i] = b[k];
        a[i].insert(a[i].begin() + k, x);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " \n"[j == m - 1];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}