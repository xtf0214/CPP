#include <iostream>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
ll n, m, a[MAXN], dat[MAXN << 2], tag[MAXN << 2];
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
inline int getPrimeNum(ll x)
{
    int res = 0;
    for (int i = 2; i * i <= x; i++)
        for (; x % i == 0; x /= i)
            res++;
    if (x > 1)
        res++;
    return res;
}
void build(int p = 1, int l = 1, int r = n)
{
    tag[p] = 0;
    if (l == r)
        return void(dat[p] = a[l]);
    int m = (l + r) >> 1;
    build(ls(p), l, m);
    build(rs(p), m + 1, r);
    dat[p] = dat[ls(p)] + dat[rs(p)];
}
inline void mark(int p, int l, int r, int k) { tag[p] += k, dat[p] += k * (r - l + 1); }
inline void push_down(int p, int l, int r)
{
    int m = (l + r) >> 1;
    mark(ls(p), l, m, tag[p]);
    mark(rs(p), m + 1, r, tag[p]);
    tag[p] = 0;
}
void update(int nl, int nr, int k, int p = 1, int l = 1, int r = n)
{
    if (nl <= l && r <= nr)
        return void(mark(p, l, r, k));
    push_down(p, l, r);
    int m = (l + r) >> 1;
    if (nl <= m)
        update(nl, nr, k, ls(p), l, m);
    if (nr > m)
        update(nl, nr, k, rs(p), m + 1, r);
    dat[p] = dat[ls(p)] + dat[rs(p)];
}
ll query(int nl, int nr, int p = 1, int l = 1, int r = n)
{
    if (nl > r || nr < l)
        return 0;
    if (nl <= l && r <= nr)
        return dat[p];
    push_down(p, l, r);
    int m = (l + r) >> 1;
    ll vl = query(nl, nr, ls(p), l, m);
    ll vr = query(nl, nr, rs(p), m + 1, r);
    return vl + vr;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] = getPrimeNum(a[i]);
    }
    build();
    cin >> m;
    while (m--)
    {
        int opt, l, r, d;
        cin >> opt >> l >> r;
        if (opt == 2)
        {
            cin >> d;
            d = getPrimeNum(d);
            update(l, r, d);
        }
        else if (opt == 1)
            cout << query(l, r) << '\n';
    }
    return 0;
}