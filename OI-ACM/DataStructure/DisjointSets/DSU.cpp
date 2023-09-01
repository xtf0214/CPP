#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int size;
    vector<int> p, sz;
    DSU(int n = 1e6) : size(n), p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { x = find(x), y = find(y), (x != y ? p[y] = x, sz[x] += sz[y], --size : 0); }
    int count(int x) { return sz[find(x)]; }
};