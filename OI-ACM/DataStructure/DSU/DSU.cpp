/** 
 * @file    :   并查集
 * @author  :   Tanphoon
 * @date    :   2024/05/30 13:53
 * @version :   2024/05/30 13:53
 */
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    DSU(int n = 1e6) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { x = find(x), y = find(y), (x != y ? p[y] = x, sz[x] += sz[y] : 0); }
    int size(int x) { return sz[find(x)]; }
};