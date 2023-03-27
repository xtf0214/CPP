#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;

int G[N][N], p[N];
bool vis[N];
int n, m, k;
set<pair<int, int>> st;

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    cin >> k;
    for (int id = 1; id <= k; id++) {
        int len;
        cin >> len;
        for (int i = 1; i <= len; i++)
            cin >> p[i];
        p[len + 1] = 0;

        bool OK = true;
        int sum = 0;
        if (len != n)
            OK = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= len + 1; i++)
            if (G[p[i - 1]][p[i]] && !vis[p[i]]) {
                sum += G[p[i - 1]][p[i]];
                vis[p[i]] = true;
            } else
                OK = false;
        if (OK)
            st.insert({sum, id});
    }
    cout << st.size() << endl;
    cout << st.begin()->second << " " << st.begin()->first << endl;
}