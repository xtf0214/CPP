/**
 * @file    :   1828C
 * @author  :   Tanphoon
 * @date    :   2023/06/22 20:00
 * @version :   2023/06/22 20:00
 * @link    :   https://codeforces.com/contest/1828/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 1;
    for (int i = n - 1; i >= 0; i--) {
        int t = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (t <= i) {
            ans = ans * (i - t + 1) % mod;
        } else {
            cout << 0 << '\n';
            return;
        }
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