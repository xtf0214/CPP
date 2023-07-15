/**
 * @file    :   I 旅行
 * @author  :   Tanphoon
 * @date    :   2023/06/15 21:36
 * @version :   2023/06/15 21:36
 * @link    :   https://ac.nowcoder.com/acm/contest/37782/I
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Node = pair<ll, int>;

const int N = 2e5 + 5;

int n, m, x;
vector<pair<int, int>> G[N];
ll d[N];
bool vis[N];

void dijkstra(int s) {
    priority_queue<Node, vector<Node>, greater<Node>> q;
    memset(d, 0x3f, sizeof(d));
    q.emplace(d[s] = 0, s);
    while (!q.empty()) {
        auto [d_u, u] = q.top();
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto &[v, w] : G[u])
            if (d[v] > d[u] + w)
                q.emplace(d[v] = d[u] + w, v);
    }
}

int main() {
    cin >> n >> m >> x;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        // u, v 是没做核酸的城市
        // u+n, v+n 是做了核酸的城市
        // 没做核酸的去做过核酸的，路径w+x
        // 做过核酸的去没做过核酸的,路径w
        G[u].emplace_back(v + n, w + x);
        G[v + n].emplace_back(u, w);

        G[v].emplace_back(u + n, w + x);
        G[u + n].emplace_back(v, w);
    }
    dijkstra(1);
    ll ans = min(d[n], d[2 * n]);
    cout << ans << '\n';
    return 0;
}