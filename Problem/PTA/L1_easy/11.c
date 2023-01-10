// 7-11 练习题
#include <stdio.h>
int main()
{
    int n, a, b, s;
    while (scanf("%d %d", &a, &b) == 2)
    {
        s = -1e4;
        if (a - b > s && a - b <= 100)
            s = a - b;
        if (b - a > s && b - a <= 100)
            s = b - a;
        if (a + b > s && a + b <= 100)
            s = a + b;
        if (a * b > s && a * b <= 100)
            s = a * b;
        printf("%d\n", s);
    }
    return 0;
}