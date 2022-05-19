#include <stdio.h>
#include <math.h>
int main()
{
    const double PI = 3.14159265;
    double a, b, s, theta;
    int d, m;
    scanf("%lf %lf %d %d %lf", &a, &b, &d, &m, &s);
    theta = d + m / 60.0 + s / 3600;
    theta = theta * PI / 180;
    printf("%.2lf", b + a * tan(theta));
    return 0;
}