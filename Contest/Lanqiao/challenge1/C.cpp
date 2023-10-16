/**
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2023/10/14 19:28
 * @version :   2023/10/14 19:28
 * @link    :   https://www.lanqiao.cn/problems/5129/learning/?contest_id=144
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    auto calc = [&](ll x) {
        ll s = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && a[j] - a[i] <= x)
                j++;
            s++;
            i = j;
        }
        return s;
    };
    ll l = -1, r = 1e9 + 5, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        (calc(mid) > k) ? l = mid : r = mid;
    }
    cout << r << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}