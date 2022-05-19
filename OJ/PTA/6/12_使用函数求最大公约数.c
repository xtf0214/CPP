#include <stdio.h>

int gcd( int x, int y );

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);
    printf("%d", gcd(x, y));

    return 0;
}

int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}