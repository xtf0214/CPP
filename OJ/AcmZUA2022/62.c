#include <stdio.h>
#include <math.h>

double dist(double x1, double y1, double x2, double y2);

int main()
{
    double x1, y1, x2, y2;

    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    printf("dist = %.2f\n", dist(x1, y1, x2, y2));

    return 0;
}

double dist(double x1, double y1, double x2, double y2)
{
    double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}