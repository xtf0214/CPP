#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &t) { return w < t.w; }
};
int V, E;
vector<Edge> edges;
vector<int> p;
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

int kruskal() {
    int sum = 0, cnt = 0;
    p.resize(V + 1);
    iota(p.begin(), p.end(), 0);
    sort(edges.begin(), edges.end());
    for (auto &[u, v, w] : edges)
        if (find(u) != find(v)) {
            sum += w;
            cnt++;
            p[find(u)] = find(v);
        }
    return cnt == V - 1 ? sum : -1;
}
signed main() {
    cin >> V >> E;
    edges.resize(E);
    for (auto &[u, v, w] : edges)
        cin >> u >> v >> w;
    cout << kruskal();
    return 0;
}
