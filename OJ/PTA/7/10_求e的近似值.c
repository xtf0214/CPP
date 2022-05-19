#include <stdio.h>
double fact(int x)
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
    double e = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        e += fact(i);
    printf("%.8lf", e);
    return 0;
}