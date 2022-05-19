#include <stdio.h>
int main()
{
    double a = 1, pi = 0, r;
    scanf("%lf", &r);
    pi += a;
    for (int i = 2; a >= r; i++)
    {
        a *= (i - 1);
        a /= 2 * i - 1;
        pi += a;
    }
    printf("%lf", pi * 2);
    return 0;
}