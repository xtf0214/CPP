/**
 * @file    :   网红点打卡攻略
 * @author  :   Tanphoon
 * @date    :   2023/12/24 23:08
 * @version :   2023/12/24 23:08
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1, vector<int>(n + 1, 0));
    for (int _ = 0; _ < m; _++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    int T;
    cin >> T;
    int cnt = 0;
    pair<int, int> ans = {0, 1e9};
    for (int id = 1; id <= T; id++) {
        int k;
        cin >> k;
        vector<int> a;
        set<int> s;
        a.push_back(0);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            s.insert(x);
        }
        a.push_back(0);
        int sum = 0;
        bool ok = true;
        for (int i = 1; i < a.size(); i++) {
            if (!G[a[i - 1]][a[i]])
                ok = false;
            sum += G[a[i - 1]][a[i]];
        }
        if (ok && s.size() == n && k == n) {
            cnt++;
            if (ans.second > sum) {
                ans = {id, sum};
            }
        }
    }
    cout << cnt << '\n';
    cout << ans.first << ' ' << ans.second;
}
