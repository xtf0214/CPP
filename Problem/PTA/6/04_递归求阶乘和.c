#include <stdio.h>

double fact(int n);
double factsum(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));

    return 0;
}
double fact(int n)
{
    if (n == 0)
        return 1;
    double s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}
double factsum(int n)
{
    double s = 0;
    for (int i = 1; i <= n; i++)
        s += fact(i);
    return s;
}
