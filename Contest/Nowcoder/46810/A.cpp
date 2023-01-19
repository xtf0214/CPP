/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/01/18 13:03
 * @version :   2023/01/18 13:03
 * @link    :   https://ac.nowcoder.com/acm/contest/46810/A
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, l, r;
    cin >> n >> a >> b >> l >> r;
    set<int> st;
    int ans = 0;
    for (int i = a; i <= b; i++)
        if (l <= n - i && n - i <= r) {
            st.insert(i);
            st.insert(n - i);
            ans++;
        }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}