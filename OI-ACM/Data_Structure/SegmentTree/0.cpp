#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 5, INF = 0x3f3f3f3f;
int n, dat[2 * MAX - 1];
void init(int n_)
{
    n = 1;
    while (n < n_)
        n *= 2;
    fill(dat, dat + 2 * n - 1, INF);
}
void update(int k, int a)
{
    k += n - 1;
    dat[k] = a;
    while (k)
    {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}
int query(int a, int b, int k, int l, int r)
{
    if (r <= a || l >= b)
        return INF;
    if (a <= l && b >= r)
        return dat[k];
    else
    {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}

int main()
{
    
    return 0;
}