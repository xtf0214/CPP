/**
 * @file    :   1530C
 * @author  :   Tanphoon
 * @date    :   2023/07/09 17:10
 * @version :   2023/07/09 17:10
 * @link    :   https://codeforces.com/contest/1530/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    auto check = [&](int x) {
        int m = (n + x) - (n + x) / 4;
        ll s1 = x * 100;
        if (x < m)
            s1 += a[m - x - 1];
        ll s2 = b[min(m, n) - 1];
        return s1 < s2;
    };
    int l = 0, r = 2 * n + 1, mid;
    if (!check(0)) {
        cout << 0 << '\n';
        return;
    }
    while (r - l > 1)
        check(mid = (l + r) / 2) ? l = mid : r = mid;
    cout << r << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}