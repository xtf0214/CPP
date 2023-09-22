/**
 * @file    :   1622A
 * @author  :   Tanphoon
 * @date    :   2023/09/21 15:31
 * @version :   2023/09/21 15:31
 * @link    :   https://codeforces.com/contest/1622/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[0] + a[1] == a[2]) {
        puts("YES");
        return;
    }
    if (a[0] == a[1] && a[2] % 2 == 0) {
        puts("YES");
    } else if (a[1] == a[2] && a[0] % 2 == 0) {
        puts("YES");
    } else {
        puts("NO");
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}