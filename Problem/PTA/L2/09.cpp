/**
 * @file    :   7-9 排座位
 * @author  :   Tanphoon
 * @date    :   2023/04/17 23:29
 * @version :   2023/04/17 23:29
 * @link    :   https://pintia.cn/problem-sets/1647006911461715968/problems/1647007456482156545
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;

struct DisjointSet {
    vector<int> p;
    DisjointSet(int n = 1e5) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { p[find(y)] = find(x); }
};

int G[N][N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    DisjointSet ds(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 1)
            ds.merge(u, v);
        else if (w == -1)
            G[u][v] = G[v][u] = -1;
    }
    while (k--) {
        int u, v;
        cin >> u >> v;
        if (ds.find(u) == ds.find(v))
            if (G[u][v] != -1)
                cout << "No problem";
            else
                cout << "OK but...";
        else if (G[u][v] == -1)
            cout << "No way";
        else
            cout << "OK";
        cout << endl;
    }
    return 0;
}