/** 
 * @file    :   E
 * @author  :   Tanphoon 
 * @date    :   2024/02/02 13:38
 * @version :   2024/02/02 13:38
 * @link    :   https://ac.nowcoder.com/acm/contest/67741/E
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pair<int, int>> vp(m);
    for (int i = 0; i < m; i++)
        cin >> vp[i].first >> vp[i].second;
    int ans = n;
    function<void(int)> dfs = [&](int cur) {
        if (cur == m) {
            int rank = 1;
            for (int i = 2; i <= n; i++)
                if (a[i] > a[1])
                    rank++;
            ans = min(ans, rank);
            return;
        }
        auto [x, y] = vp[cur];
        a[x] += 3;
        dfs(cur + 1);
        a[x] -= 3;

        a[y] += 3;
        dfs(cur + 1);
        a[y] -= 3;

        a[x]++, a[y]++;
        dfs(cur + 1);
        a[x]--, a[y]--;
    };
    dfs(0);
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