#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 2e5 + 5;

vector<int> G[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 1), nxt(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nxt[mp[a[i]]] = i;
        mp[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (1 <= i - 1)
            G[i].push_back(i - 1);
        if (i + 1 <= n)
            G[i].push_back(i + 1);
        if (nxt[i] != 0)
            G[i].push_back(nxt[i]);
    };
    vector<int> f(n + 1, 1e9);
    auto bfs = [&](int u) {
        queue<int> q;
        q.push(u);
        f[u] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) 
                if (f[v] > f[u] + 1) {
                    f[v] = f[u] + 1;
                    q.push(v);
                }
        }
    };
    bfs(1);
    cout << f[n] << '\n';
    return 0;
}