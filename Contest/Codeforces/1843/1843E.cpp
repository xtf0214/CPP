/**
 * @file    :   Codeforces Round 881 (Div. 3) 1843E
 * @author  :   Tanphoon
 * @date    :   2023/06/21 00:14
 * @version :   2023/06/21 00:14
 * @link    :   https://codeforces.com/contest/1843/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, q;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto &[l, r] : a) 
        cin >> l >> r;

    cin >> q;
    vector<int> b(q + 1);
    for (int i = 1; i <= q; i++)
        cin >> b[i];
        
    int l = 0, r = q + 1, mid;
    auto check = [&](int x) {
        vector<int> pr(n + 1);
        for (int i = 1; i <= x; i++)
            pr[b[i]] = 1;
        for (int i = 1; i <= n; i++)
            pr[i] += pr[i - 1];
        for (auto &[l, r] : a) {
            int len = r - l + 1;
            int one = pr[r] - pr[l - 1];
            if (one * 2 > len) {
                return true;
            }
        }
        return false;
    };
    while (r - l > 1)
        check(mid = (l + r) / 2) ? r = mid : l = mid;
    if (r == q + 1)
        cout << -1 << '\n';
    else
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