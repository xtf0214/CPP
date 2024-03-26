/**
 * @file    :   1867A
 * @author  :   Tanphoon
 * @date    :   2023/09/12 09:35
 * @version :   2023/09/12 09:35
 * @link    :   https://codeforces.com/contest/1867/problem/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        a[i][2] = n - i;
    sort(a.begin(), a.end(), [](const auto &x, const auto &y) { return x[1] < y[1]; });
    for (int i = 0; i < n; i++)
        cout << a[i][2] << ' ';
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}