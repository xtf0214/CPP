/**
 * @file    :   1922B
 * @author  :   Tanphoon
 * @date    :   2024/01/22 12:43
 * @version :   2024/01/22 12:43
 * @link    :   https://codeforces.com/contest/1922/problem/B
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
    long long ans = 0;
    int preSum = 0;
    for (auto &[x, y] : mp) {
        if (y >= 3) {
            ans += 1LL * y * (y - 1) * (y - 2) / 6;
        }
        if (y >= 2) {
            ans += 1LL * y * (y - 1) / 2 * preSum;
        }
        preSum += y;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}