#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
const int N = 1e2 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int p[N];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void merge(int x, int y) { find(x) != find(y) ? p[find(x)] = find(y) : 0; }
void init() { iota(p, p + N, 0); }
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vvi G(n + 1, vi(n + 1, INF));
    for (int i = 0, u, v, w; i < m; i++)
    {
        cin >> u >> v >> w;
        if (w == 1)
            merge(u, v);
        else if (w == -1)
            G[u][v] = G[v][u] = -1;
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v))
            if (G[u][v] != -1)
                cout << "No problem";
            else
                cout << "OK but...";
        else if (G[u][v] == -1)
            cout << "No way";
        else
            cout << "OK";
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}