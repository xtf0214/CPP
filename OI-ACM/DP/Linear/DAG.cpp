// P2196 挖地雷
// https://www.luogu.com.cn/problem/P2196
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, ans;
vector<vector<int>> G;
vector<int> w, dp, pre;
void print(int u) {
    if (pre[u] == 0)
        return void(cout << u);
    print(pre[u]);
    cout << " " << u;
}
void rec() {
    dp = w;
    pre.resize(n + 1);
    for (int v = 1; v <= n; v++) {
        for (int u = 1; u < v; u++)
            if (G[u][v] && dp[v] < dp[u] + w[v]) {
                dp[v] = dp[u] + w[v];
                pre[v] = u;
            }
        if (dp[ans] < dp[v]) // 记录答案
            ans = v;
    }
    print(ans);
    cout << endl << dp[ans];
}
int main() {
    cin >> n;
    G.assign(n + 1, vector<int>(n + 1));
    w.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> G[i][j];
    rec();
}