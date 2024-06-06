/**
 * @file    :   F 7/11 73分
 * @author  :   Tanphoon
 * @date    :   2024/04/13 16:12
 * @version :   2024/04/13 16:12
 * @link    :   https://www.dotcpp.com/oj/train/1118/
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include <DEBUG.h>
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> G(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    double res = 0;
    function<int(int, int)> bfs = [&](int u, int dep) -> int {
        vector<int> vis(n + 1);
        queue<pair<int, int>> q;
        q.push({u, dep});
        vis[u] = 1;
        int s = 0;
        while (!q.empty()) {
            int u = q.front().first;
            int dep = q.front().second;
            q.pop();
            if (dep == 0)
                continue;
            s += 1;
            for (int v : G[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, dep - 1});
                }
            }
        }
        return s;
    };
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int ans = bfs(x, y + 1);
        res += ans;
    }
    res /= double(q);
    cout << fixed << setprecision(2) << res << endl;
    return 0;
}