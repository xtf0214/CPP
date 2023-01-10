#include <stdio.h>
int main()
{
    double e = 1, t = 1;
    for (int i = 1; t >= 0.00001; i++)
    {
        e += t;
        t /= (i + 1);
    }
    printf("%lf", e);
    return 0;
} //迭代法