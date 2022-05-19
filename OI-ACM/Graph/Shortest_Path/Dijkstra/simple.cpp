#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100, INF = 0x29292929;
int V;
int cost[MAX_V][MAX_V];

struct Node
{
    int p = -1, d = INF;
    bool vis = false;
} nodes[MAX_V];

void Dijkstra(int s)
{
    nodes[s].d = 0;
    while (true)
    {
        int u = -1, minv = INF;
        //在V-MST各节点中寻找与MST距离最近的结点u
        for (int i = 0; i < V; i++)
            // if (minv > nodes[i].d && !nodes[i].vis)
            //     u = i, minv = nodes[i].d;
            if ((u == -1 || nodes[i].d < nodes[u].d) && !nodes[i].vis)
                u = i;
        //找不到，即说明MST已包含V的全部结点
        if (u == -1 /*  && minv == INF */)
            break;
        // MST加入结点u
        nodes[u].vis = true;
        //松弛操作，当MST加入结点u后，更新起点与连接u和V-MST各节点的最短距离E[v].d
        for (int v = 0; v < V; v++)
            if (!nodes[v].vis && cost[u][v] != INF)
                if (cost[u][v] + nodes[u].d < nodes[v].d)
                    nodes[v].d = cost[u][v] + nodes[u].d, nodes[v].p = u;
    }
    for (int i = 0; i < V; i++)
    {
        printf("d[%d] = %d\n", i, nodes[i].d);
        for (int u = i; u != -1; u = nodes[u].p)
            u == i ? printf("%d", u) : printf(" -> %d", u);
        printf("\n");
    }
}
int main()
{
    cin >> V;
    for (int i = 0; i < V; i++)
        for (int j = 0, e; j < V; j++)
            (cin >> e), cost[i][j] = (e == -1) ? INF : e;
    Dijkstra(0);
    return 0;
}
