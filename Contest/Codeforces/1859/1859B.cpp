/**
 * @file    :   1859B
 * @author  :   Tanphoon
 * @date    :   2023/08/12 22:59
 * @version :   2023/08/12 22:59
 * @link    :   https://codeforces.com/contest/1859/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        a[i].resize(sz);
        for (int &x : a[i])
            cin >> x;
        partial_sort(a[i].begin(), a[i].begin() + 2, a[i].end());
    }
    if (n == 1) {
        cout << a[0][0] << '\n';
        return;
    }
    pair<int, int> mn1 = {INT_MAX, -1}, mn2 = {INT_MAX, -1}; // 最小和次小
    for (int i = 0; i < n; i++) {
        if (a[i][0] < mn1.first)
            mn1 = {a[i][0], i};
        if (a[i][1] < mn2.first)
            mn2 = {a[i][1], i};
    }
    cout << a;
    ll ans = mn1.first;
    for (int i = 0; i < n; i++)
        if (i != mn2.second)
            ans = ans + a[i][1];
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}