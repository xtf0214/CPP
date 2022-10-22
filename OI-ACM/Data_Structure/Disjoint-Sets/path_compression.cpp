#include <iostream>
using namespace std;
const int MAX = 10000 + 5;
int p[MAX];
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
void merge(int x, int y) { find(x) != find(y) ? p[find(x)] = find(y) : 0; }
int main()
{
    int n, a, b, q, op;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < q; i++)
    {
        cin >> op >> a >> b;
        if (op == 0)
            merge(a, b);
        else if (op == 1)
            find(a) == find(b) ? (cout << 1 << endl) : (cout << 0 << endl);
    }
    return 0;
}