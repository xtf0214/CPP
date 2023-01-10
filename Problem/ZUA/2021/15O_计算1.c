#include <stdio.h>
int fact(int n)
{
    if (n == 0)
        return 1;
    int s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
int main()
{
    double e = 0;
    for (int i = 0; i <= 10; i++)
        e += 1.0 / fact(i);
    printf("%lf", e);
    return 0;
}