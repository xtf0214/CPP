/**
 * @file    :   P2014 [CTSC1997] 选课
 * @author  :   Tanphoon
 * @date    :   2023/03/03 17:18
 * @version :   2023/03/03 17:18
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> val, sz;
vector<vector<int>> G;
vector<vector<int>> f;

void dfs(int u) {
    f[u][1] = val[u];
    f[u][0] = 0;
    for (int v : G[u]) {
        dfs(v);
        for (int j = m + 1; j >= 2; j--) // 倒序自动滚动
            for (int k = 0; k < j; k++)  // 正序倒序无妨
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
    }
}
int main() {
    cin >> n >> m;
    G.resize(n + 1);
    val.resize(n + 1);
    sz.resize(n + 1);
    f.resize(n + 1, vector<int>(m + 2));
    for (int u, v = 1, w; v <= n; v++) {
        cin >> u >> w;
        G[u].push_back(v);
        val[v] = w;
    }
    dfs(0);
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= m + 1; j++)
    //         cerr << f[i][j] << " \n"[j == m + 1];
    cout << f[0][m + 1];
    return 0;
}
/*
7  4
2  2
0  1
0  4
2  1
7  1
7  6
2  2
0 0 4 5 9 13
0 2 0 0 0 0
0 1 3 9 11 12
0 4 0 0 0 0
0 1 0 0 0 0
0 1 0 0 0 0
0 6 0 0 0 0
0 2 8 9 8 8
*/
