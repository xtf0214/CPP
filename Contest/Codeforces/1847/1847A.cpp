/** 
 * @file    :   1847A
 * @author  :   Tanphoon 
 * @date    :   2023/07/07 12:55
 * @version :   2023/07/07 12:55
 * @link    :   https://codeforces.com/contest/1847/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0)
            b[i] = {abs(a[i] - a[i - 1]), i};
    }
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int i = 1; i <= n - k; i++) {
        ans += b[i].first;
        a[b[i].second] = 0;    
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