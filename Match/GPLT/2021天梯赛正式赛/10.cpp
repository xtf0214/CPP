#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 10000 + 5;
vector<int> edges[MAX_V];
int p[MAX_V], d[MAX_V];
queue<int> q;
vector<int> ans;
int V, E;
int main()
{
    cin >> V;
    memset(p, -1, sizeof(p));
    for (int u = 0, k, v; u < V; u++)
    {
        cin >> k;
        while (k--)
        {
            cin >> v;
            p[v] = u;
            edges[u].push_back(v);
        }
    }
    int st = 0, dis = 0, end;
    for (int i = 0; i < V; i++)
        if (p[i] == -1)
            st = i;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : edges[u])
        {
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    end = max_element(d, d + V) - d;
    cout << d[end] + 1 << endl;
    for (int i = end; i != -1; i = p[i])
        ans.push_back(i);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        i ? (cout << " " << ans[i]) : (cout << ans[i]);
    return 0;
}
