#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> p;
    DisjointSet(int n = 1e9) : p(vector<int>(n)) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { find(x) != find(y) ? p[find(y)] = find(x) : 0; }
};
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    DisjointSet dset(n + 1);
    for (int i = 0; i < m; i++) {
        int k, x, y;
        cin >> k >> x;
        for (int j = 1; j < k; j++) {
            cin >> y;
            dset.merge(x, y);
        }
    }
    map<int, int> Map;
    for (int i = 1; i <= n; i++)
        Map[dset.find(i)]++;
    int ans = 0;
    for (auto it : Map)
        ans = max(ans, it.second);
    cout << ans << endl;
    return 0;
}
