#include <stdio.h>
int main()
{
    int x, cnt = 0, s = 0;
    scanf("%d", &x);
    while (x > 0)
    {
        s += x % 10;
        cnt++;
        x /= 10;
    }
    printf("%d %d", cnt, s);
    return 0;
}