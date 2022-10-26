#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100000 + 5;
vector<int> edges[MAX_V], save;
int V, E;
int main()
{
    cin >> V >> E;
    for (int u = 1, v, k; u <= V; u++)
    {
        cin >> k;
        while (k--)
        {
            cin >> v;
            edges[u].push_back(v);
        }
    }
}