#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 20;
int V, E;
vector<int> adjs[MAX_V];
bool vis[MAX_V];

void dfs(int u)
{
    int k = 0;
    queue<int> s[100];
    int st[100];
    memset(st, -1, sizeof(st));
    s[k].push(u);
    while (k >= 0)
    {
        if (s[k].empty())
        {
            // for (int i = 0; i < k; i++)
            //     printf("-");
            // printf("%d)\n", st[k]);
            k--;
            continue;
        }
        int u = s[k].front();
        s[k].pop();
        if (vis[u])
            continue;
        st[k] = u;
        vis[u] = true;
        if (u != st[k] && st[k] != -1)
        {
            for (int i = 0; i < k; i++)
                printf("-");
            printf("%d)\n", st[k]);
        }
        for (int i = 0; i < k; i++)
            printf("-");
        printf("(%d\n", u);
        for (int v : adjs[u])
            if (!vis[v])
                s[k + 1].push(v);
        k++;
    }
}
int main()
{
    ifstream fin("VE.in");
    fin >> V >> E;
    fill(vis, vis + V, false);
    for (int i = 0, u, v; i < E; i++)
    {
        fin >> u >> v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    for (int i = 0; i < V; i++)
        if (!vis[i])
            dfs(i);
}