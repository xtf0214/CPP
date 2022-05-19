#include <stdio.h>
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d %d", gcd(x, y), lcm(x, y));
    return 0;
}