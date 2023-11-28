/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/11/25 17:15
 * @version :   2023/11/25 17:15
 * @link    :   https://codeforces.com/gym/104095/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef _DEBUG
#include "DEBUG.h"
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5;

int dist(int x, int y) { return x * x + y * y; }

inline void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        int h, t, r;
        if (op == 1) {
            cin >> h;
            a[i] = {op, x, y, h};
        } else {
            cin >> t >> r;
            t *= 3;
            a[i] = {op, x, y, 1};
            pair<int, int> mn{-1, 1e18};
            for (int j = i - 1; j >= 0; j--)
                if (a[j][0] == 1 && a[j][3] > 0 && mn.second >= dist(a[j][1] - a[i][1], a[j][2] - a[i][2])) {
                    mn = {j, dist(a[j][1] - a[i][1], a[j][2] - a[i][2])};
                }
            if (mn.first == -1)
                continue;
            x = a[mn.first][1], y = a[mn.first][2];
            int ok = false;
            for (int j = 0; j <= i - 1; j++) {
                debug(dist(a[j][1] - x, a[j][2] - y));
                if (a[j][0] == 1 && a[j][3] > 0 && dist(a[j][1] - x, a[j][2] - y) <= r * r) {
                    a[j][3] -= t;
                    if (a[j][3] > 0) {
                        ok = true;
                    }
                }
            }
            if (ok)
                a[i][3] = 0;
            debug(a);
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 1) {
            cout << (a[i][3] > 0 ? "Yes" : "No");
        } else {
            cout << (a[i][3] ? "Yes" : "No");
        }
        cout << "\n";
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}