#include <stdio.h>
int main()
{
    double s = 0;
    for (int i = 0; i <= 10; i++)
    {
        if (i % 2 == 0)
            s += 1.0 / fact(i);
        else
            s -= 1.0 / fact(i);
    }
    printf("%lf", s);
    return 0;
}