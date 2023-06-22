/**
 * @file    :   Codeforces Round 877 (Div. 2) 1838B
 * @author  :   Tanphoon
 * @date    :   2023/06/08 17:20
 * @version :   2023/06/08 17:20
 * @link    :   https://codeforces.com/contest/1838/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        idx[x] = i;
    }
    if (idx[n] < min(idx[1], idx[2])) {
        cout << idx[n] << ' ' << min(idx[1], idx[2]) << '\n';
    } else if (idx[n] > max(idx[1], idx[2])) {
        cout << idx[n] << ' ' << max(idx[1], idx[2]) << '\n';
    } else {
        cout << idx[1] << ' ' << idx[2] << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}