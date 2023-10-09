/**
 * @file    :   1627B
 * @author  :   Tanphoon
 * @date    :   2023/10/09 20:33
 * @version :   2023/10/09 20:33
 * @link    :   https://codeforces.com/contest/1627/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d.push_back(max(i, n - 1 - i) + max(j, m - 1 - j));
    sort(d.begin(), d.end());
    for (int i = 0; i < n * m; i++)
        cout << d[i] << ' ';
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