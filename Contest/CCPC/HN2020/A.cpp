/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/11/25 17:01
 * @version :   2023/11/25 17:01
 * @link    :   https://codeforces.com/gym/104095/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(m + 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back({y, i});
    }
    for (int i = 1; i <= m; i++) {
        sort(v[i].begin(), v[i].end(),
             [](const auto &a, const auto &b) { return a.first != b.first ? a.first > b.first : a.second < b.second; });
        cout << v[i][0].second + 1 << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}