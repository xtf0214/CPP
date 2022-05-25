#include <bits/stdc++.h>
using namespace std;
const int  MAX_V = 100,INF = 0x3f3f3f3f;
int V, E;
int cost[MAX_V][MAX_V];

void floyd()
{
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}
int main()
{
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cost[i][j] = (i == j) ? 0 : INF;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v >> w;
        cost[u][v] = w;
    }
    floyd();
    bool negative = false;
    for (int i = 0; i < V; i++)
        if (cost[i][i] < 0)
            negative = true;
    if (negative)
        cout << "NEGATIVE CYCLE" << endl;
    else
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (j)
                    cout << " ";
                cost[i][j] == INF ? (cout << "INF") : (cout << cost[i][j]);
            }
            cout << endl;
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