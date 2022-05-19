#include <stdio.h>
int main()
{
    int a, b, c, d, maxn;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    maxn = a > b ? a : b;
    maxn = maxn > c ? maxn : c;
    maxn = maxn > d ? maxn : d;
    printf("%d", maxn);
    return 0;
}