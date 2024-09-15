/** 
 * @file    :   C
 * @author  :   Tanphoon
 * @date    :   2024/09/16 00:17
 * @version :   2024/09/16 00:17
 * @link    :   https://codeforces.com/gym/105184/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

inline void solve() {
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> a(N);
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        a[l].push_back({r, i});
    }
    vector<int> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    for (int i = 0; i < m; i++) {
        for (auto it : a[i])
            q.push(it);
        while (!q.empty() && q.top().first < i)
            q.pop();
        if (q.empty())
            break;
        ans.push_back(q.top().second);
        q.pop();
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}