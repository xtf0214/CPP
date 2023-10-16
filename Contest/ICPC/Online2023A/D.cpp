#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU {
    vector<int> p, sz_n, sz_m;
    DSU(int n) : p(n), sz_n(n, 1), sz_m(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            p[y] = x;
            sz_n[x] += sz_n[y];
            sz_m[x] += sz_m[y];
        }
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    DSU st(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        st.sz_m[st.find(u)] += 1;
        st.merge(u, v);
    }
    vector<pair<int, int>> a;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int p = st.find(i);
        if (p == i) {
            int nn = st.sz_n[p];
            int mm = st.sz_m[p];
            a.push_back({nn, mm});
            ans += nn * (nn - 1) / 2 - mm;
        }
    }
    if (ans) {
        cout << ans << '\n';
        return 0;
    }
    sort(a.begin(), a.end());
    cout << a[0].first * a[1].first << '\n';
}