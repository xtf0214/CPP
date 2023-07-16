/**
 * @file    :   1848A
 * @author  :   Tanphoon
 * @date    :   2023/07/16 23:14
 * @version :   2023/07/16 23:14
 * @link    :   https://codeforces.com/contest/1848/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    cin >> x >> y;
    int ok = 1;
    while (k--) {
        int x1, y1;
        cin >> x1 >> y1;
        if ((abs(x1 - x) + abs(y1 - y)) % 2 == 0)
            ok = 0;
    }
    puts(ok ? "YES" : "NO");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}