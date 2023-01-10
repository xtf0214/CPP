#include <bits/stdc++.h>
using namespace std;
int n, m, k, cost[MAX_V][MAX_V];
const int MAX_V = 1000, INF = 0x3f3f3f3f;
struct Node
{
    int d = INF, id;
    bool used = false;
    Node(int id, int d) : id(id), d(d) {}
};
void bfs(int x)
{
    queue<Node> q;
    q.push(Node(x,0));
    while (!q.empty())
    {
        Node top = q.front();
        for(int i=1;i<=n;i++)
            if(cost[top.id][i]!=INF)
    }
    
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost[i][j] = INF;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        cost[a][b] = cost[b][a] = 1;
    }
    for (int i = 0, t; i < k; i++)
    {
        cin >> t;
        bfs(t);
    }
}