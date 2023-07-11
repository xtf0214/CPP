/**
 * @file    :   1844C
 * @author  :   Tanphoon
 * @date    :   2023/07/11 23:43
 * @version :   2023/07/11 23:43
 * @link    :   https://codeforces.com/contest/1844/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = max(a[i], 0LL);
    }
    if (*max_element(b.begin(), b.end()) == 0LL) {
        cout << *max_element(a.begin(), a.end()) << '\n';
        return;
    }
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1)
            ans2 += b[i];
        else
            ans1 += b[i];
    }
    cout << max(ans1, ans2) << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}