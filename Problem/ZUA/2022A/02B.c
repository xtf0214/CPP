#include <stdio.h>
int min(int x, int y) { return x < y ? x : y; }
int main()
{
    int m, n, ret;
    scanf("%d%d", &m, &n);
    ret = min(m, n);
    printf("%d", ret);
    return 0;
}