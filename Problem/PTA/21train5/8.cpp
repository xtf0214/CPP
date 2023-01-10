#include <bits/stdc++.h>
using namespace std;
using Node = pair<int, int>;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[++i == v.size()])
const int INF = 0x3f3f3f3f;

int V, E, S, D;
vector<vector<Node>> G;
vector<bool> vis;
vector<int> help, dist, pre, pathNum, helpSum;
void dijkstra(int s) {
    vis.assign(V, false);
    dist.assign(V, INF), pre.assign(V, -1);
    pathNum.assign(V, 1), helpSum = help;
    dist[S] = 0;
    while (true) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || dist[u] > dist[i]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        for (auto &[v, w] : G[u])
            //这次循环再找以v为中转点更得到的更短的路径
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pre[v] = u;
                pathNum[v] = pathNum[u];
                helpSum[v] = helpSum[u] + help[v];
                //新的路径和原最短路径长度相等，说明都是最短路，这时当前记录的最短路条数就要加上原来记录的这个长度的最短路条数
            } else if (dist[v] == dist[u] + w) {
                pathNum[v] += pathNum[u];
                //只有新的最短路的救援队数量比之前多时，才把路径信息更新成当前新的最短路的路径信息
                if (helpSum[v] < helpSum[u] + help[v]) {
                    helpSum[v] = helpSum[u] + help[v];
                    pre[v] = u;
                }
            }
    }
}
signed main() {
    cin >> V >> E >> S >> D;
    G.resize(V);
    help.resize(V);
    for (int i = 0; i < V; i++)
        cin >> help[i];
    for (int i = 0, u, v, w; i < E; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(S);
    deque<int> ans;
    cout << pathNum[D] << " " << helpSum[D] << endl;
    for (int p = D; p != -1; p = pre[p])
        ans.push_front(p);
    print(ans);
    return 0;
}
