#include <stdio.h>
int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    int r = gcd(m, n);
    printf("%d %d", r, m * n / r); //(m/r)*(n/r)*r
    return 0;
}