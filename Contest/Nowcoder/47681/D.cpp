/** 
 * @file    :   D
 * @author  :   Tanphoon 
 * @date    :   2023/09/29 11:26
 * @version :   2023/09/29 11:26
 * @link    :   https://ac.nowcoder.com/acm/contest/47681/D
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1 + 3);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > 0) {
            int cnt = (a[i] - 1) / k + 1;
            ans += cnt;
            for (int j = 0; j < 3; j++)
                a[i + j] -= cnt * k;
        }
    cout << ans << '\n';
}

signed main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}