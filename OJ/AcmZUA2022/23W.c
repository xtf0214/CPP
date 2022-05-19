#include <stdio.h>
#include <math.h>
int flower(int x)
{
    int a = x % 10, b = x / 10 % 10, c = x / 100;
    return a * a * a + b * b * b + c * c * c == x ? 1 : 0;
}
int main()
{
    int x, ret;
    scanf("%d", &x);
    ret = flower(x);
    if (ret == 1)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
    return 0;
}