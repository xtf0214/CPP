/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2023/08/24 01:07
 * @version :   2023/08/24 01:07
 * @link    :   https://ac.nowcoder.com/acm/contest/63746/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<array<int, 3>> opt(m);
    for (auto &[d, l, r] : opt)
        cin >> d >> l >> r;
    auto check = [&](int x) {
        vector<int> d(n + 2);
        for (int i = 0; i < x; i++) {
            auto &[c, l, r] = opt[i];
            d[l] += c;
            d[r + 1] -= c;
        }
        for (int i = 1; i <= n; i++) {
            d[i] += d[i - 1];
            if (d[i] > a[i])
                return false;
        }
        return true;
    };
    int l = -1, r = m, mid;
    while (r - l > 1)
        check(mid = (l + r) / 2) ? l = mid : r = mid;
    if (r == m)
        cout << 0 << '\n';
    else {
        cout << -1 << '\n';
        cout << r << '\n';
    }
    return 0;
}