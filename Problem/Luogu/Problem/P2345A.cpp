#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long wz[20010], yy[20010], n, mn = 20000;
long long ans;
long long read()
{
    long long xx = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        xx = xx * 10 + ch - '0';
        ch = getchar();
    }
    return xx;
}
struct node
{
    long long xi;
    long long vi;
} a[20010];
bool cmp(node x, node y)
{
    return x.vi < y.vi;
}
int lobit(int x) { return x & (-x); }
void crwz(int x)
{
    for (; x <= mn; x += lobit(x))
        wz[x]++;
}
int z(int x)
{
    int sum = 0;
    for (; x >= 1; x -= lobit(x))
        sum += wz[x];
    return sum;
}
void cryy(int x, int v)
{
    for (; x <= mn; x += lobit(x))
        yy[x] += v;
}
int y(int x)
{
    int sum = 0;
    for (; x >= 1; x -= lobit(x))
        sum += yy[x];
    return sum;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i].vi = read(), a[i].xi = read();
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        int j = a[i].xi;
        cout << a[i].vi << endl;
        cout << z(j - 1) << endl;
        cout << y(j - 1) << endl;
        cout << y(mn) - y(j) << endl;
        cout << z(mn) - z(j) << endl;
        ans += a[i].vi * (z(j - 1) * j - y(j - 1) + y(mn) - y(j) - (z(mn) - z(j)) * j);
        cout << endl;
        crwz(a[i].xi);
        cryy(j, a[i].xi);
    }
    printf("%lld", ans);
    return 0;
}