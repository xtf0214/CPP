#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, d, s;
    scanf("%lf %lf %lf", &a, &b, &c);
    d = (a + b + c) / 2;
    s = sqrt(d * (d - a) * (d - b) * (d - c));
    printf("%.2lf", s);
    return 0;
}