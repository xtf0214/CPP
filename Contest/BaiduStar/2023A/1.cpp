#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e4 + 5;
int n, m;
vector<int> G[N];
int s1, s2;

int d1[N], d2[N], d3[N];

void bfs(int d[], int s) {
    queue<int> q;
    memset(d, 0x3f, sizeof(int) * N);
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u])
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
}

int main() {
    int TE, FE, S;
    cin >> TE >> FE >> S;
    cin >> s1 >> s2 >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs(d1, s1);
    bfs(d2, s2);
    bfs(d3, n);
    ll ans = 8e18;
    for (int i = 1; i <= n; i++) {
        if (d1[i] < n && d2[i] < n && d3[i] < n) {
            ll d = 0LL + d1[i] * TE + d2[i] * FE + d3[i] * (TE + FE - S);
            ans = min(ans, d);
        }
    }
    cout << (ans == 8e18 ? -1 : ans);
}
