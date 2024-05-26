/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/05/26 19:11
 * @version :   2024/05/26 19:11
 * @link    :   https://ac.nowcoder.com/acm/contest/82526/D
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    cout << max_element(mp.begin(), mp.end(), [](const auto a, const auto b) { return a.second < b.second; })->second
         << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}