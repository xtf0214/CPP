#include <stdio.h>
#include <math.h>
double Dfact(int x)
{
    if (x == 0)
        return 1;
    double s = 1;
    for (int i = 1; i <= x; i++)
        s *= 1.0 / i;
    return s;
}
int main()
{
    double x, a = 1, ex = 0;
    scanf("%lf", &x);
    for (int i = 0; a >= 0.00001 || a <= -0.00001; i++)
    {
        a = pow(x, i) * Dfact(i);
        ex += a;
    }
    printf("%.4lf", ex);
    return 0;
}