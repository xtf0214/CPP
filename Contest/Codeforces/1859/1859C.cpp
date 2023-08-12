/**
 * @file    :   1859C
 * @author  :   Tanphoon
 * @date    :   2023/08/12 23:19
 * @version :   2023/08/12 23:19
 * @link    :   https://codeforces.com/contest/1859/problem/C
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    auto calc = [](const vector<int> &a) {
        int s = 0, mx = 0, n = a.size();
        for (int i = 0; i < n; i++) {
            s += a[i] * (i + 1);
            mx = max(mx, a[i] * (i + 1));
        }
        s -= mx;
        return s;
    };

    pair<int, vector<int>> ans = {0, {}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            a[j] = j + 1;
        for (int j = i, k = n; j < n; j++, k--)
            a[j] = k;
        int s = calc(a);
        if (ans.first < s)
            ans = {s, a};
    }
    cout << ans.first << '\n';
    // print(mx.second);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}