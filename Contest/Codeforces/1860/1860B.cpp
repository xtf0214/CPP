/**
 * @file    :   1860B
 * @author  :   Tanphoon
 * @date    :   2024/03/24 01:19
 * @version :   2024/03/24 01:19
 * @link    :   https://codeforces.com/contest/1860/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int m, k, regular_1, regular_k;
    cin >> m >> k >> regular_1 >> regular_k;
    int need_k = m / k;
    int need_1 = m % k;
    int left_regular_1 = max(0, regular_1 - need_1);
    int fancy_1 = max(0, need_1 - regular_1);
    int fancy_k = max(0, need_k - regular_k);
    int replace_k = min(left_regular_1 / k, fancy_k); // 剩余的普通1元金币可以替换多少精美l元金币
    int ans = fancy_1 + fancy_k - replace_k;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}