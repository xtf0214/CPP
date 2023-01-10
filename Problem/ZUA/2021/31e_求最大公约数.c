#include <stdio.h>
int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}
int main()
{
    int x, y, r;
    scanf("%d %d", &x, &y);
    r = gcd(x, y);
    printf("%d", r);
    return 0;
}
