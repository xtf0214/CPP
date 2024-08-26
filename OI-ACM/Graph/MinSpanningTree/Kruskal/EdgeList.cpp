#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;

int V, E;
struct Edge {
    int u, v, w;
    bool operator<(const Edge &e) const { return w < e.w; }
};
vector<Edge> edges;

int p[N];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

int kruskal() {
    int sum = 0;
    sort(edges.begin(), edges.end());
    iota(p, p + N, 0);
    for (auto [u, v, w] : edges)
        if (find(u) != find(v)) {
            sum += w;
            p[find(u)] = find(v);
        }
    return sum;
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    cout << kruskal() << endl;
    return 0;
}