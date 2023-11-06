/**
 * @file    :   1799B
 * @author  :   Tanphoon
 * @date    :   2023/06/19 20:56
 * @version :   2023/11/06 11:16
 * @link    :   https://codeforces.com/contest/1799/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#ifdef _DEBUG
#include "DEBUG.h"
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    if (count(a.begin(), a.end(), a[0]) == n) {
        cout << 0 << '\n';
        return;
    }
    if (count(a.begin(), a.end(), 1) > 0) {
        cout << -1 << '\n';
        return;
    }
    vector<pii> ans;
    while (count(a.begin(), a.end(), a[0]) < n) {
        int i = 1;
        while (a[0] == a[i])
            i++;
        if (a[0] > a[i]) {
            ans.push_back({1, i + 1});
            a[0] = (a[0] - 1) / a[i] + 1;
        } else {
            ans.push_back({i + 1, 1});
            a[i] = (a[i] - 1) / a[0] + 1;
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) 
        cout << x << ' ' << y << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}