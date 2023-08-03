/**
 * @file    :   M
 * @author  :   Tanphoon
 * @date    :   2023/08/02 13:27
 * @version :   2023/08/02 13:27
 * @link    :   https://ac.nowcoder.com/acm/contest/62880/M
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, m;
vector<int> G[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    for (int u = 1; u <= n; u++) {
        if (G[u].empty())
            cout << 1 << ' ';
        else {
            int s = 0;
            for (int v : G[u])
                s += G[v].size();
            cout << s << ' ';
        }
    }
    return 0;
}