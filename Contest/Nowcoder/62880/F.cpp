/**
 * @file    :   F
 * @author  :   Tanphoon
 * @date    :   2023/08/02 16:51
 * @version :   2023/08/02 16:51
 * @link    :   https://ac.nowcoder.com/acm/contest/62880/F
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, sz;
    DSU(int n = 1e6) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { x = find(x), y = find(y), (x != y ? p[y] = x, sz[x] += sz[y] : 0); }
    int size(int x) { return sz[find(x)]; }
};

int main() {
    int n;
    cin >> n;
    DSU d(n);
    vector<tuple<int, int, int>> a(n);
    for (auto &[x, y, v] : a)
        cin >> x >> y >> v;
    vector<tuple<int, int, int>> b;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            auto [x1, y1, v1] = a[i];
            auto [x2, y2, v2] = a[j];
            double d = hypot(x1 - x2, y1 - y2);
            int v = v1 + v2;
            if (v == 0)
                b.push_back({1e9, i, j});
            else
                b.push_back({ceil(d / v), i, j});
        }
    sort(b.begin(), b.end());
    vector<int> h(1005);
    for (auto &[t, i, j] : b)
        if (d.find(i) != d.find(j)) {
            d.merge(i, j);
            h[t]++;
        }
    for (int i = 1; i <= 1000; i++)
        h[i] += h[i - 1];
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << n - h[x] << '\n';
    }
    return 0;
}