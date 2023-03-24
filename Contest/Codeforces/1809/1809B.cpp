/**
 * @file    :   1809B
 * @author  :   Tanphoon
 * @date    :   2023/03/24 00:07
 * @version :   2023/03/24 00:07
 * @link    :   https://codeforces.com/contest/1809/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve() {
    ll n;
    cin >> n;
    if (n == 1)
        return 0;
    auto check = [&](ll k) { return (k + 1) * (k + 1) < n; };
    int l = -1, r = 1e9, mid;
    while (r - l > 1)
        check(mid = (l + r) >> 1) ? l = mid : r = mid;
    return r;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}