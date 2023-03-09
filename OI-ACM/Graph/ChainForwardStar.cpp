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
    using Edge = pair<int, int>;
    vector<int> head, next;
    vector<Edge> edges;
    int E;
    ChainForwardStar(int V = 0) { head.resize(V + 1, -1); }
    void addEdge(int u, int v, int w = 1) {
        edges.push_back({v, w});
        next.push_back(head[u]);
        head[u] = E++;
    }
    vector<Edge> operator[](int u) {
        vector<Edge> res;
        for (int i = head[u]; ~i; i = next[i])
            res.push_back(edges[i]);
        return res;
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
    for (int u = 0; u < V; u++) {
        for (auto &[v, w] : G[u])
            cout << u << " " << v << " " << w << endl;
        cout << endl;
    }
}
