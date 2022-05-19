#include <stdio.h>
#include <math.h>
int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a % b) : a;
}
int main()
{
    int n, p, q, r, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d/%d", &x, &y);
        r = gcd(abs(x), abs(y));
        x /= r, y /= r;
        if (i == 0)
        {
            p = x, q = y;
            continue;
        }
        p = x * q + y * p;
        q = y * q;
        r = gcd(abs(p), abs(q));
        p /= r, q /= r;
    }
    if (q == 1)
        printf("%d", p);
    else if (p > q)
        printf("%d %d/%d", p / q, p % q, q);
    else
        printf("%d/%d", p, q);
    return 0;
}