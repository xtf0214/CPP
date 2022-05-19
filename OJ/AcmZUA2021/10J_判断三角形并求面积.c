#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, d, s;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("不能构成三角形");
        return 0;
    }
    d = (a + b + c) / 2;
    s = sqrt(d * (d - a) * (d - b) * (d - c));
    printf("%.2lf", s);
    return 0;
}