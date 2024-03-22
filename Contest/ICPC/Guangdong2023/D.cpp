/**
 * @file    :   problemD
 * @author  :   Tanphoon
 * @date    :   2024/01/24 15:14
 * @version :   2024/01/24 15:14
 * @link    :   https://codeforces.com/gym/104369/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.end(), [](const auto &x, const auto &y) { return x.first - x.second > y.first - y.second; });
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        sum += a[i].second;
    if (m >= 2 * n - 1) 
        ans = sum;
    sum += a[1].first - a[1].second;
    for (int i = 2; i <= n; i++) {
        sum += a[i].first - a[i].second;
        if (m >= 2 * n - i)
            ans = max(ans, sum);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}