#include <stdio.h>
#define MAX 10000 + 5
int main()
{
    long long x, cnt = 0;
    scanf("%d", &x);
    while (x > 1)
    {
        if (x % 2 == 0)
            x /= 2;
        else
            x = x * 3 + 1;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}