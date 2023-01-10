#include <stdio.h>
int main()
{
    int a, b, c, maxn;
    scanf("%d %d %d", &a, &b, &c);
    maxn = a > b ? a : b;
    maxn = maxn > c ? maxn : c;
    printf("%d", maxn);
    return 0;
}