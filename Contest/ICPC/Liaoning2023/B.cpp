/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2023/11/14 15:24
 * @version :   2023/11/14 15:24
 * @link    :   https://ac.nowcoder.com/acm/contest/68504/B
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    double a;
    cin >> a;
    a *= 100;
    int l = 0, r = 1;
    for (int s = 1; s < 10000; s++) {
        while ((l + 1) * 10000.0 / s < a) {
            l++;
        }
        while ((r - 1) * 10000.0 / s > a) {
            r--;
        }
        for (int i = l; i <= r; i++) {
            if (round(i * 10000.0 / s) == a) {
                cout << s << '\n';
                return;
            }
        }
        r++;
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