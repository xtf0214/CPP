#include <bits/stdc++.h>
using namespace std;

vector<int> G[10];
bool vis[10];

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u])
        if (!vis[v])
            dfs(v);
}
void solve() {
    memset(vis, 0, sizeof(vis));
    int st;
    string s;
    cin >> s;
    for (int i = 0; i < 8; i++)
        vis[i + 1] = s[i] - '0';
    for (int i = 1; i <= 8; i++)
        if (!vis[i]) {
            dfs(i);
            break;
        }
    if (count(vis + 1, vis + 1 + 8, 0))
        puts("No");
    else
        puts("Yes");
}

int main() {
    int T;
    for (int i = 1; i <= 8; i++) {
        G[i].push_back((i + 2) % 8 + 1);
        G[i].push_back((i + 4) % 8 + 1);
    }
    cin >> T;
    while (T--)
        solve();
}