#include <bits/stdc++.h>
using namespace std;
struct DisjointSet {
    vector<int> p;
    DisjointSet(int n = 1e6) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void unite(int x, int y) { p[find(x)] = find(y); }
};
int main() {
    int n, a, b, q, op;
    cin >> n >> q;
    DisjointSet dset(n);
    for (int i = 0; i < q; i++) {
        cin >> op >> a >> b;
        if (op == 0)
            dset.unite(a, b);
        else if (op == 1)
            puts(dset.find(a) == dset.find(b) ? "1" : "0");
    }
    return 0;
}