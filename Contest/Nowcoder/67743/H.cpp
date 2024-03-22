/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2024/02/26 23:20
 * @version :   2024/02/26 23:20
 * @link    :   https://ac.nowcoder.com/acm/contest/67743/H
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i][0] >> s[i][1] >> s[i][2];
        s[i][0]--, s[i][1]--;
    }
    vector<int> a(3);
    auto judge = [&]() {
        for (auto [x, y, w] : s) {
            if (w == 1) {
                if (a[x] >= a[y])
                    return 0;
            } else {
                if (a[x] < a[y])
                    return 0;
            }
        }
        return 1;
    };
    bool ok = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                a = {i, j, k};
                ok |= judge();
            }
    cout << (ok ? "Yes\n" : "No\n");
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}