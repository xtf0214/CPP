#include <stdio.h>
int main()
{
    int s = 0, cnt = 0;
    int x;
    scanf("%d", &x);
    while (x)
        s += x % 10, cnt++, x /= 10;
    printf("%d %d", cnt, s);
    return 0;
}