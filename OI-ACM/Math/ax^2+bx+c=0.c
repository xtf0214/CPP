#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c;
    scanf("%lf,%lf,%lf", &a, &b, &c);
    if (a == 0)
    {
        if (b == 0)
        {
            printf("x");
            return 0;
        }
        printf("%.2lf", -c / b);
        return 0;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0)
        printf("x");
    else if (delta == 0)
        printf("%.2lf", -b / (2.0 * a));
    else
    {
        double m = (-b + sqrt(delta)) / (2.0 * a), n = (-b - sqrt(delta)) / (2.0 * a);
        if (m > n)
            printf("%.2lf %.2lf", m, n);
        else
            printf("%.2lf %.2lf", n, m);
    }
    return 0;
}