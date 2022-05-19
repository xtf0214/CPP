#include <stdio.h>
int LCM(int a, int b)
{
    int r, mul = a * b;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return mul / a;
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    int ret;
    ret = LCM(x, y);
    printf("%d", ret);
    return 0;
}