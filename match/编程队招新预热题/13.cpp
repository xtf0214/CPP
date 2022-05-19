#include <iostream>
#include <vector>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, p;

public:
    /* 初始化最大为n的并查集 */
    DisjointSet(int n)
    {
        rank.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++)
            makeSet(i);
    }
    /* 创建只有x的新集合 */
    void makeSet(int x) { p[x] = x, rank[x] = 0; }
    /* 寻找x所在的集合 */
    int find(int x) { return p[x] == x ? x : (p[x] = find(p[x])); }
    /* 判断x和y是否在同一集合 */
    bool same(int x, int y) { return find(x) == find(y); }
    /* 合并x和y所在集合 */
    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return;
        (rank[x] < rank[y]) ? (p[x] = y) : (p[y] = x);
        if (rank[x] == rank[y])
            rank[x]++;
    }
};
int main()
{
    int n, a, b, q, t;
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n + 1);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d", &t, &a, &b);
        if (t == 1)
            ds.unite(a, b);
        else if (t == 2)
            ds.same(a, b) ? printf("Y\n") : printf("N\n");
    }
    return 0;
}
