#include <stdio.h>

int main() {
    int n, i = 1;
    scanf("%d", &n);
    do {
        int a, b, c, p, q, t;
        a = n % 10;
        b = n / 10 % 10;
        c = n / 100 % 10;
        if (a > b)
            t = a, a = b, b = t;
        if (a > c)
            t = a, a = c, c = t;
        if (b > c)
            t = b, b = c, c = t;
        p = c * 100 + b * 10 + a;
        q = a * 100 + b * 10 + c;
        printf("%d: %d - %d = %d\n", i++, p, q, p - q);
        n = p - q;
    } while (n != 495);
}