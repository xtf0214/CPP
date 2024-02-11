/**
 * @file    :   Tokitsukaze_and_Eliminate_hard
 * @author  :   Tanphoon
 * @date    :   2024/02/06 19:36
 * @version :   2024/02/06 19:36
 * @link    :   https://ac.nowcoder.com/acm/contest/67742/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int>> color;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        color[a[i]].push_back(i);
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (auto &[k, v] : color)
        q.push({v.back(), k});
    int cur = n, ans = 0;
    while (!q.empty()) {
        auto [pos, k] = q.top();
        q.pop();
        if (pos > cur)
            continue;
        ans++;
        while (cur >= pos) {
            color[a[cur]].pop_back();
            if (!color[a[cur]].empty())
                q.push({color[a[cur]].back(), a[cur]});
            cur--;
        }
    }
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