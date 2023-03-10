/**
 * @file    :   LinkEdge
 * @author  :   Tanphoon
 * @date    :   2023/02/28 16:33
 * @version :   2023/03/11 04:18
 */
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using Edge = pair<int, int>;

struct ChainForwardStar;
struct iter {
    ChainForwardStar &_G;
    int _end;
    mutable int _cur;
    iter(ChainForwardStar &G, int begin) : _G(G), _end(-1), _cur(begin) {}
    ~iter() = default;
    iter &begin(void) { return *this; }
    iter &end(void) { return *this; }
    iter &operator++(void);
    bool operator!=(const iter &End) { return this->_cur != End._end; }
    Edge &operator*(void);
};

struct ChainForwardStar {
    vector<int> head, next;
    vector<Edge> edges;
    int E;
    ChainForwardStar(int V = 0) { head.resize(V + 1, -1); }
    void addEdge(int u, int v, int w = 1) {
        edges.push_back({v, w});
        next.push_back(head[u]);
        head[u] = E++;
    }
    iter operator[](int u) { return iter(*this, head[u]); }
};

iter &iter::operator++(void) { return _cur = _G.next[_cur], *this; }
Edge &iter::operator*(void) { return _G.edges[_cur]; }

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
    // 设置 begin() end() != * ++
    // for (auto it = G[u].begin(); it != G[u].end(); it++)
    //     auto &[v, w] = *it;
}
