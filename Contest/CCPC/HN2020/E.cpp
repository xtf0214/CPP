/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2023/11/25 18:10
 * @version :   2023/11/25 18:10
 * @link    :   https://codeforces.com/gym/104095/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> vp(n);
    vector<int> d;
    set<int> st;
    for (int i = 0; i < n; i++) {
        auto &[l, r, w] = vp[i];
        cin >> l >> r >> w;
        d.push_back(l);
        d.push_back(r);
        d.push_back(r + 1);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    auto get = [&d](int k) { return lower_bound(d.begin(), d.end(), k) - d.begin() + 1; };
    for (int i = 0; i < n; i++) {
        vp[i][0] = get(vp[i][0]);
        vp[i][1] = get(vp[i][1]);
    }
    int m = d.size();
    vector<int> a(m + 2), b(m + 2);
    for (int i = 0; i < n; i++) {
        auto [l, r, w] = vp[i];
        b[l] += 1, b[r + 1] -= 1;
        a[l] ^= w, a[r + 1] ^= w;
    }
    int ans = -1;
    for (int i = 1; i <= m; i++) {
        b[i] += b[i - 1];
        a[i] ^= a[i - 1];
        if (b[i] >= k) {
            ans = max(ans, a[i]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}