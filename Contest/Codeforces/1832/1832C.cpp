/**
 * @file    :   1832C
 * @author  :   Tanphoon
 * @date    :   2023/06/23 18:16
 * @version :   2023/06/23 18:16
 * @link    :   https://codeforces.com/contest/1832/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
void solve() { 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    n = unique(a.begin(), a.end()) - a.begin();
    int ans = n;
    for (int i = 0; i + 2 < n; i++) {
        ans -= (a[i] < a[i + 1] && a[i + 1] < a[i + 2]);
        ans -= (a[i] > a[i + 1] && a[i + 1] > a[i + 2]);
    }
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