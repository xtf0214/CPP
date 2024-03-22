/** 
 * @file    :   D
 * @author  :   Tanphoon 
 * @date    :   2024/02/27 16:58
 * @version :   2024/02/27 16:58
 * @link    :   
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = -1e9, ans = -1e9;
    int l = 0, r = 0;
    for (int i = 0, lst = 0; i < n; i++) {
        if (mx < 0) {
            mx = a[i];
            lst = i;
        } else {
            mx += a[i];
        }
        if (ans < mx) {
            ans = mx;
            l = lst, r = i;
        }
    }
    int mn = *min_element(a.begin() + l, a.begin() + r + 1);
    cout << ans << '\n';
    cout << l << ' ' << r << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}