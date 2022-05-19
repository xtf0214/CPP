#include <stdio.h>
int LCM(int a, int b)
{
    int m = a, n = b;
    while (b > 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return m * n / a;
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    int ret;
    ret = x > y ? LCM(x, y) : LCM(y, x);
    printf("%d", ret);
    return 0;
}