#include <stdio.h>
#define MAX 10000 + 5
#define PI 3.1415926536
int main()
{
    double r,h;
    scanf("%lf %lf", &r, &h);
    printf("Area = %.3lf", 2 * PI * r * h + 2 * PI * r * r);
    return 0;
}