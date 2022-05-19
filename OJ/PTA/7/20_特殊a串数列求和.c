#include <stdio.h>
#include <math.h>
int main()
{
    int a, n, s = 0;
    scanf("%d %d", &a, &n);
    for (int i = 1; i <= n; i++)
    {
        int b = 0;
        for (int j = 1; j <= i; j++)
            b += a * pow(10, j - 1);
        s += b;
    }
    printf("s = %d", s);
    return 0;
}