/**
 * @file    :   LinkEdge
 * @author  :   Tanphoon
 * @date    :   2023/02/28 16:33
 * @version :   2023/03/11 04:18
 */
#include <iostream>
#include <vector>
#include <ranges>
using namespace std;
using Edge = pair<int, int>;

struct ChainForwardStar {
    struct iter {
        ChainForwardStar &_G;
        int _val;
        iter(ChainForwardStar &G, int val) : _G(G), _val(val) {}
        const iter begin() const { return *this; }
        const iter end() const { return iter(_G, -1); }
        iter &operator++() { return _val = _G.next[_val], *this; }
        iter operator++(int) { return iter(_G, _G.next[_val]); }
        friend bool operator!=(const iter &lhs, const iter &rhs) { return lhs._val != rhs._val; }
        Edge &operator*() { return _G.edges[_val]; }
    };
    vector<int> head, next;
    vector<Edge> edges;
    int E = 0;
    ChainForwardStar(int V = 0) { head.resize(V + 1, -1); }
    void addEdge(int u, int v, int w = 1) {
        edges.push_back({v, w});
        next.push_back(head[u]);
        head[u] = E++;
    }
    iter operator[](int u) { return iter(*this, head[u]); }
};

int main() {
    int V, E;
    // cin >> V >> E;
    V = 5, E = 7;
    ChainForwardStar G(V);
    // for (int i = 0; i < E; i++) {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     G.addEdge(u, v, w);
    // }
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(1, 5);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    for (int u = 1; u <= V; u++) {
        cout << u << " son: \n";
        for (auto &[v, w] : G[u])
            cout << u << ' ' << v << ' ' << w << '\n';
        cout << "\n";
    }
    // 设置 begin() end() != * ++
    for (int u = 1; u <= V; u++) {
        cout << u << " son: \n";
        for (auto it = G[u].begin(); it != G[u].end(); ++it) {
            auto &[v, w] = *it;
            cout << u << ' ' << v << ' ' << w << '\n';
        }
        cout << "\n";
    }
}