#include <iostream>
#include <vector>
using namespace std;
struct DisjointSet
{
    vector<int> rank, p;
    DisjointSet(int n = 0)
    {
        rank.resize(n), p.resize(n);
        for (int i = 0; i < n; i++)
            rank[i] = 0, p[i] = i;
    }
    int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
    bool same(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        rank[x] < rank[y] ? p[x] = y : p[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
    }
};
int main()
{
    int n, a, b, q;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n + 1);
    for (int i = 0, op; i < q; i++)
    {
        cin >> op >> a >> b;
        if (op == 1)
            ds.unite(a, b);
        else if (op == 2)
            ds.same(a, b) ? (cout << "Y" << endl) : (cout << "N" << endl);
    }
    return 0;
}