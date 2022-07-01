#include <bits/stdc++.h>
using namespace std;
const int logn = 21;
const int maxn = 2000001;
int f[maxn][logn + 1], Logn[maxn + 1];

inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x * f;
}
void pre()
{
    Logn[1] = 0, Logn[2] = 1;
    for (int i = 3; i < maxn; i++)
        Logn[i] = Logn[i / 2] + 1;
}
void init(int n)
{
    for (int j = 1; j <= logn; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}
int query(int l, int r)
{
    int s = Logn[r - l + 1];
    return max(f[l][s], f[r - (1 << s) + 1][s]);
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i][0] = read();
    pre();
    init(n);
    for (int i = 1; i <= m; i++)
    {
        int l = read(), r = read();
        printf("%d\n", query(l, r));
    }
    return 0;
}