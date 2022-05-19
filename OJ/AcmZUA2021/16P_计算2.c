#include <stdio.h>
double Dfact(int n)
{
    if (n == 0)
        return 1;
    double s = 1;
    for (int i = 1; i <= n; i++)
        s *= 1.0 / i;
    return s;
}
int main()
{
    double e = 0, t = Dfact(0);
    for (int i = 1; t >= 0.00001; i++)
    {
        e += t;
        t = Dfact(i);
    }
    printf("%lf", e);
    return 0;
}