/** 
 * @file    :   Tokitsukaze_and_Short_Path_plus
 * @author  :   Tanphoon 
 * @date    :   2024/02/10 18:01
 * @version :   2024/02/10 18:01
 * @link    :   https://ac.nowcoder.com/acm/contest/67742/J
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#else
#define debug(...) 0
#endif
const int N = 1e6 + 5;

inline void solve() {
    int n;
    cin >> n;
    // w(i,j)=2*max(a[i],a[j])
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += 2 * a[i] * i;
    }
    ans *= 2;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}