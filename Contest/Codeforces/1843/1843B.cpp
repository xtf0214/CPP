/**
 * @file    :   Codeforces Round 881 (Div. 3) 1843B
 * @author  :   Tanphoon
 * @date    :   2023/06/20 22:47
 * @version :   2023/06/20 22:47
 * @link    :   https://codeforces.com/contest/1843/problem/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += abs(x);
        if (x)
            a.push_back(x);
    }
    n = a.size();
    int res = 0;
    for (int i = 0, j = 0; i < n && j < n;) {
        while (j < n && a[j] * a[i] > 0)
            j++;
        if (a[i] < 0)
            res++;
        i = j;
    }
    cout << ans << ' ' << res << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}