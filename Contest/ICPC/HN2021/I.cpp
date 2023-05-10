#include <bits/stdc++.h>
using namespace std;

vector<int> G[10];
bool vis[10];

bool dfs(int u) {
    if (vis[u])
        return false;
    for (int v : G[u])
        dfs(v);
}
void solve() {
    memset(vis, 0, sizeof(vis));
    int st;
    for (int i = 1; i <= 8; i++) {
        cin >> vis[i];
    }


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