/**
 * @file    :   L
 * @author  :   Tanphoon
 * @date    :   2023/09/14 22:51
 * @version :   2023/09/14 22:51
 * @link    :   https://ac.nowcoder.com/acm/contest/39585/L
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c && b == d) {
        puts("NO");
    } else if (a * d == b * c) {
        puts("YES");
    } else if (b * b * c * c - 2 * a * b * c * d + a * a * d * d == 1) {
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