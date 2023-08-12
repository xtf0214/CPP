/**
 * @file    :   G
 * @author  :   Tanphoon
 * @date    :   2023/08/10 17:31
 * @version :   2023/08/10 17:31
 * @link    :   https://ac.nowcoder.com/acm/contest/62977/G
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef _DEBUG
#include "DEBUG.h"
#endif
const int N = 1e6 + 5;

int kruskal(vector<array<int, 3>> &edges, int n) {
    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b) { return a[2] < b[2]; });
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x) { return x == p[x] ? x : p[x] = find(p[x]); };
    int sum = 0;
    for (auto &[u, v, w] : edges)
        if (find(u) != find(v)) {
            p[find(v)] = find(u);
            sum += w;
        }
    return sum;
}

void solve(int n) {
    vector<array<int, 3>> edges;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
                edges.push_back({i, j, i & j});
    int s = kruskal(edges, n);
    if (s) {
        cout << n << " " << s << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    // while (T--)
    for (int i = 1; i <= 540; i++)
        solve(i);
    return 0;
}