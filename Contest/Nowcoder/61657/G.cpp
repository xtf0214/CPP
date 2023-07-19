/**
 * @file    :   爬山
 * @author  :   Tanphoon
 * @date    :   2023/07/19 13:50
 * @version :   2023/07/19 13:50
 * @link    :   https://ac.nowcoder.com/acm/contest/61657/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto check = [&](ll x) {
        ll s = 0;
        for (ll i : a)
            if (i > x)
                s += (i - x) * 2;
        return s >= m;
    };
    ll l = -1, r = 1e9 + 5, mid;
    while (r - l > 1)
        check(mid = (l + r) / 2) ? l = mid : r = mid;
    cout << l;
    return 0;
}