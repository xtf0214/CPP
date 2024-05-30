/** 
 * @file    :   全功能并查集
 * @author  :   Tanphoon
 * @date    :   2024/05/30 13:53
 * @version :   2024/05/30 13:53
 */
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int size;
    vector<int> p, V, E, cycle;
    DSU(int n = 1e6) : size(n), p(n), V(n, 1), E(n), cycle(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    bool merge(int x, int y) {
        if (x == y)
            cycle[find(x)] = 1;
        x = find(x), y = find(y);
        E[x]++;
        if (x == y)
            return false;
        if (x < y)
            swap(x, y);
        p[y] = x, V[x] += V[y], E[x] += E[y], cycle[x] |= cycle[y], --size;
        return false;
    }
    int size(int x) { return V[find(x)]; }
    int edge(int x) { return E[find(x)]; }
    bool cycle(int x) { return cycle[find(x)]; }
};