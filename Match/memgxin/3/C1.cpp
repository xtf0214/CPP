#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define ls p << 1
#define rs p << 1 | 1
const int N = 2e5 + 5;
int a[N];
struct no
{
    int l, r;
    int sum, lz;
} t[N << 2];
void pushup(int p)
{
    t[p].sum = (t[ls].sum + t[rs].sum);
}
void build(int p, int l, int r)
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].sum = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}
void pushdown(int p)
{
    if (t[p].lz)
    {
        t[ls].lz += t[p].lz;
        t[rs].lz += t[p].lz;
        t[ls].sum += t[p].lz * (t[ls].r - t[ls].l + 1);
        t[rs].sum += t[p].lz * (t[rs].r - t[rs].l + 1);
        t[p].lz = 0;
    }
}
void modify(int p, int l, int r, int v)
{
    if (r >= t[p].r && t[p].l >= l)
    {
        t[p].lz += v;
        t[p].sum += v * (t[p].r - t[p].l + 1);
        return;
    }
    pushdown(p);
    int mid = t[p].l + t[p].r >> 1;
    if (mid >= l)
        modify(ls, l, r, v);
    if (r > mid)
        modify(rs, l, r, v);
    pushup(p);
}
int query(int p, int l, int r)
{
    if (r >= t[p].r && t[p].l >= l)
    {
        return t[p].sum;
    }
    pushdown(p);
    int mid = t[p].l + t[p].r >> 1;
    int ans = 0;
    if (mid >= l)
        ans += query(ls, l, r);
    if (r > mid)
        ans += query(rs, l, r);
    return ans;
}
bool vis[3000];
vector<int> pri;
int work(int x)
{
    int c = 0;
    for (int i = 0; i < pri.size() && pri[i] * pri[i] <= x; i++)
    {
        int j = pri[i];
        while (x % j == 0)
        {
            c++;
            x /= j;
        }
    }
    if (x > 1)
        c++;
    return c;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i <= 2000; i++)
    {
        if (vis[i] == 0)
            pri.push_back(i);
        for (int j = i * 2; j <= 2000; j += i)
        {
            vis[j] = 1;
        }
    }
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] = work(a[i]);
    build(1, 1, n);
    cin >> m;
    while (m--)
    {
        int c;
        int x, y, z;
        cin >> c;
        if (c == 1)
        {
            cin >> x >> y;
            cout << query(1, x, y) << "\n";
        }
        else
        {
            cin >> x >> y >> z;
            modify(1, x, y, work(z));
        }
    }
}