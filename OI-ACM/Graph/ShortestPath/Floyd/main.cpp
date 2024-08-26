#include <bits/stdc++.h>
using namespace std;
const int N = 100, INF = 1e9;

int V, E;
int G[N][N];

void floyd() {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
int main() {
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            G[i][j] = (i == j) ? 0 : INF;
    for (int i = 0, u, v, w; i < E; i++) {
        cin >> u >> v >> w;
        G[u][v] = w;
    }
    floyd();
    bool negative = false;
    for (int i = 0; i < V; i++)
        if (G[i][i] < 0)
            negative = true;
    if (negative) {
        cout << "NEGATIVE CYCLE" << '\n';
    } else {
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                cout << (G[i][j] == INF ? INFINITY : G[i][j]) << " \n"[j == V - 1];
    }
    return 0;
}
/*
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7 */