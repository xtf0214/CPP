// 7-41 二分法求多项式单根
#include <math.h>
#include <stdio.h>
float a0, a1, a2, a3;
double f(double x) { return a3 * x * x * x + a2 * x * x + a1 * x + a0; }

double solve(double l, double r) {
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (f(mid) == 0)
            return mid;
        if (f(l) * f(mid) > 0)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main() {
    double a, b;
    scanf("%lf %lf %lf %;f", &a3, &a2, &a1, &a0);
    scanf("%lf %lf", &a, &b);
    printf("%.2lf", solve(a, b));
}