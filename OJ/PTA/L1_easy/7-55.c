#include <stdio.h>
int main()
{
    int n, s = 0;
    scanf("%d", &n);
    while (n > 0)
    {
        s += n & 1 ? 1 : 0;
        n = n >> 1;
    }

    // while (n > 0)
    // {
    //     n -= (n & -n);
    //     s++;
    // }

    // while (n > 0)
    // {
    //     n = n & (n - 1);
    //     s++;
    // }
    printf("%d", s);
}