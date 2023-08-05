/**
 * @file    :   J
 * @author  :   Tanphoon
 * @date    :   2023/08/04 22:33
 * @version :   2023/08/04 22:33
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, k;
    cin >> m >> k;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    auto calc = [&](ll x) {
        ll cur = 0, n = 0;
        for (int i = 0; i < m; i++) {
            cur += a[i];
            cur = max(cur, 0LL);
            if (cur >= x) {
                cur = 0;
                n++;
            }
        }
        return n;
    };
    ll l = 0, r = 1e18 + 5, mid;
    while (r - l > 1)
        (calc(mid = (l + r) >> 1) > k) ? l = mid : r = mid;
    if (calc(r) != k) {
        cout << -1;
        return 0;
    }
    cout << r << ' ';
    l = 0, r = 1e18 + 5;
    while (r - l > 1)
        (calc(mid = (l + r) >> 1) >= k) ? l = mid : r = mid;
    cout << l << '\n';
    return 0;
}