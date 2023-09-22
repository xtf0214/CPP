/**
 * @file    :   1622B
 * @author  :   Tanphoon
 * @date    :   2023/09/21 15:40
 * @version :   2023/09/21 15:40
 * @link    :   https://codeforces.com/contest/1622/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1];
        a[i][2] = i;
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        a[i][0] = s[i] - '0';
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        a[i][3] = i + 1;
    sort(a.begin(), a.end(), [](const auto &a, const auto &b) { return a[2] < b[2]; });
    for (int i = 0; i < n; i++)
        cout << a[i][3] << ' ';
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