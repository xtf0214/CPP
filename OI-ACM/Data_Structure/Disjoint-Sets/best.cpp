#include <iostream>
#include <vector>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, p;

public:
    DisjointSet(int n)
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
    int n, a, b, q, t;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);
    for (int i = 0; i < q; i++)
    {
        cin >> t >> a >> b;
        if (t == 0)
            ds.unite(a, b);
        else if (t == 1)
            ds.same(a, b) ? (cout << 1 << endl) : (cout << 0 << endl);
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
