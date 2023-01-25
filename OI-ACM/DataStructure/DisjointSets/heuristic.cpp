#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> rank, p;
    DisjointSet(int n = 1e9) : p(vector<int>(n)), rank(vector<int>(n)) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        rank[x] < rank[y] ? p[x] = y : p[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
};
int main() {
    int n, a, b, q, t;
    cin >> n >> q;
    DisjointSet ds(n);
    for (int i = 0; i < q; i++) {
        cin >> t >> a >> b;
        if (t == 0)
            ds.unite(a, b);
        else if (t == 1)
            puts(ds.find(a) == ds.find(b) ? "1" : "0");
    }
    return 0;
}
/* 5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0 */
