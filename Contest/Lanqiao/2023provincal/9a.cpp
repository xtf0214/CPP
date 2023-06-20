/**
 * @file    :   9 景区导游
 * @author  :   Tanphoon
 * @date    :   2023/04/25 10:59
 * @version :   2023/04/25 10:59
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {

    int n, k;
    cin >> n >> k;
    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, 0x3f3f3f3f));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
        d[0][i] = d[i][0] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        d[u][v] = d[v][u] = t;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    vector<int> q(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> q[i];
    ll ans = 0;
    for (int i = 1; i <= k; i++)
        ans += d[q[i - 1]][q[i]];
    for (int i = 1; i <= k; i++) {
        int l = i - 1, r = i + 1;
        cout << ans - d[q[l]][q[i]] - d[q[i]][q[r]] + d[q[l]][q[r]] << " ";
    }
    return 0;
}