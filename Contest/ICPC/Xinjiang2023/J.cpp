/** 
 * @file    :   J
 * @author  :   Tanphoon 
 * @date    :   2024/01/22 14:35
 * @version :   2024/01/22 14:35
 * @link    :   https://ac.nowcoder.com/acm/contest/74088/B
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    vector<int> deg(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] >= 2) {
            s += deg[i] * (deg[i] - 1) / 2;
        }
    }
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}