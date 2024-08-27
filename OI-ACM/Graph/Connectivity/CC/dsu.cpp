#include <bits/stdc++.h>
using namespace std;
const int N = 100;

int V, E;
vector<int> G[N];

int p[N];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

int cc() {
    int res = 0;
    for (int i = 0; i < V; i++)
        p[i] = i;
    for (int u = 0; u < V; u++)
        for (int v : G[u])
            if (find(u) != find(v))
                p[u] = v;
    for (int i = 0; i < V; i++)
        if (find(i) == i)
            res++;
    return res;
}
int main() {
    cin >> V >> E;
    for (int i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << cc();
}
/* 
8 10
0 1
0 2
0 3
1 2
2 3
3 4
3 5
5 6
5 7
6 7 */