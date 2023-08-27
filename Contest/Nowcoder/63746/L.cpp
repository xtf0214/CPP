/**
 * @file    :   L
 * @author  :   Tanphoon
 * @date    :   2023/08/24 13:01
 * @version :   2023/08/24 13:01
 * @link    :   https://ac.nowcoder.com/acm/contest/63746/L
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector dist(n + 1, vector<int>(n + 1, 1e9));
    vector f(n + 1, vector(n + 1, vector<int>(65)));
    while (m--) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        f[u][v][0] = 1;
    }
    for (int t = 1; t <= 64; t++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    if (f[i][k][t - 1] && f[k][j][t - 1]) {
                        f[i][j][t] = 1;
                        dist[i][j] = 1;
                    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    cout << dist[1][n] << '\n';
}
