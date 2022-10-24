#include <stdio.h>
int main()
{
    int s, v;
    int a, b, c, d;
    scanf("%d %d", &s, &v);
    if (s % v == 0)
        a = s / v + 10;
    else
        a = s / v + 11;
    if (a > 60 * 8)
        a = 24 * 60 + 8 * 60 - a;
    else
        a = 60 * 8 - a;
    b = a / 60;
    c = a % 60;
    printf("%02d:%02d", b, c);
}
