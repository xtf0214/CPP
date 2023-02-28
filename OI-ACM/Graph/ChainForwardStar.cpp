/**
 * @file    :   LinkEdge
 * @author  :   Tanphoon
 * @date    :   2023/02/28 16:33
 * @version :   2023/02/28 16:33
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ChainForwardStar {
    vector<int> head, next;
    vector<pair<int, int>> edges;
    int E;
    ChainForwardStar(int V = 0) { head.resize(V + 1, -1); }
    void addEdge(int u, int v, int w = 1) {
        edges.push_back({v, w});
        next.push_back(head[u]);
        head[u] = E++;
    }
};
int main() {
    int V, E;
    cin >> V >> E;
    ChainForwardStar G(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.addEdge(u, v, w);
    }
    for (int u = 1; u <= V; u++) {
        for (int i = G.head[u]; ~i; i = G.next[i]) {
            auto &[v, w] = G.edges[i];
            cout << u << " " << v << " " << w << endl;
        }
        cout << endl;
    }
}
