#include <bits/stdc++.h>
using namespace std;
const int V_max = 1000 + 5, E_max = 3000 + 5;
int V, E;
vector<int> edges[V_max];
bool vis[V_max];
bool find(int u, int v)
{
    for (auto to : edges[u])
        if (to == v)
            return true;
    return false;
}
bool circle()
{
    int n1;
    cin >> n1;
    int a[V_max];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];

        if (i == 0)
        {
            vis[a[i]] = true;
            continue;
        }
        if (i == n1 - 1 && a[i] != a[0])
            return false;
        if (!find(a[i - 1], a[i]) || (vis[a[i]] && i != n1 - 1))
            return false;
        vis[i] = true;
    }
    for (int i = 1; i <= V; i++)
        if (!vis[i])
            return false;
    // return true;
}
int main()
{
    cin >> V >> E;
    for (int i = 0, u, v, w; i < E; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        bool a = circle();
        if (a)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}