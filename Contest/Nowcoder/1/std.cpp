#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
const int max_n = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }
int n, q;
struct Node
{
    int l, r, add, v;
} tr[max_n << 2];

void pu(int u) { tr[u].v = tr[ls(u)].v * tr[rs(u)].v % mod; }
void pd(int u)
{
    if (tr[u].add)
    {
        tr[ls(u)].v = 1, tr[rs(u)].v = 1;
        tr[ls(u)].add = 1, tr[rs(u)].add = 1;
        tr[u].add = 0;
    }
}
void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 1};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(ls(u), l, mid), build(rs(u), mid + 1, r);
    pu(u);
}

void modify(int u, int l, int r, int c)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].add = c;
        tr[u].v = c;
        return;
    }
    pd(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(ls(u), l, r, c);
    if (r > mid)
        modify(rs(u), l, r, c);
    pu(u);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;

    build(1, 1, 100000);

    for (int i = 1; i <= q; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a;
            cin >> a;
            modify(1, i, i, a);
        }
        if (op == 2)
        {
            int l, r, d;
            cin >> l >> r >> d;
            modify(1, l, r, d);
        }
        else if (op == 3)
            cout << tr[1].v % mod << endl;
    }
    return 0;
}