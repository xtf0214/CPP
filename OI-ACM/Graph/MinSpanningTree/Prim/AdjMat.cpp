#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;

int V;
int G[N][N];
int d[N];
bool vis[N];

int Prim() {
    int sum = 0;
    fill(d, d + V, INF);
    fill(vis, vis + V, false);
    d[0] = 0;
    while (true) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if ((u == -1 || d[i] < d[u]) && !vis[i])
                u = i;
        if (u == -1)
            break;
        vis[u] = true;
        sum += d[u];
        for (int v = 0; v < V; v++)
            d[v] = min(d[v], G[u][v]);
    }
    return sum;
}
int main() {
    cin >> V;
    for (int i = 0; i < V; i++)
        for (int j = 0, e; j < V; j++)
            (cin >> e), G[i][j] = (e == -1) ? INF : e;
    cout << Prim();
    return 0;
}
/* 
7
-1 10  3 -1 18 11 -1
10 -1  5  1 -1 -1 -1
 3  5 -1  2 -1  7  5
-1  1  2 -1 -1 -1  2 
18 -1 -1 -1 -1  1 -1
11 -1  7 -1  1 -1  2
-1 -1  5  2 -1  2 -1 */