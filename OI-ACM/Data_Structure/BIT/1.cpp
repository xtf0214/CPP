#include <bits/stdc++.h>
#define lowbit(x) x & -x
using namespace std;
const int MAX = 10000 + 5;
int a[MAX], c[MAX], n;
int sum(int x)
{
    int res = 0;
    while (x)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
void add(int x, int d)
{
    while (x <= n)
    {
        c[x] += d;
        x += lowbit(x);
    }
}
int query(int l, int r) { return sum(r) - sum(l - 1); }
int main()
{
    n = 16;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= 16; i++)
        add(i, i);
    cout << query(1, 10);
    return 0;
}