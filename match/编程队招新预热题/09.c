#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; n != 495; i++)
    {
        int a, b, c, p, q;
        a = n % 10;
        b = n / 10 % 10;
        c = n / 100 % 10;
        if (a > b)
            a = a + b, b = a - b, a = a - b;
        if (a > c)
            a = a + c, c = a - c, a = a - c;
        if (b > c)
            b = b + c, c = b - c, b = b - c;
        p = a * 100 + b * 10 + c;
        q = c * 100 + b * 10 + a;
        printf("%d: %d - %d = %d", i, p, q, p - q);
        n = p - q;
    }
}