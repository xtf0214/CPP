#include <stdio.h>
#include <math.h>
double area(double x, double y, double z)
{
    double p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}
int main()
{
    double l, m, n, ret;
    scanf("%lf%lf%lf", &l, &m, &n);
    ret = area(l, m, n);
    printf("%.6lf", ret);
    return 0;
}