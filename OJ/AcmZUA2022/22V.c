#include <stdio.h>
int Sum(int x)
{
    int s = 0;
    while (x)
        s += x % 10, x /= 10;
    return s;
}
int main()
{
    int n, ret;
    scanf("%d", &n);
    ret = Sum(n);
    printf("%d", ret);
    return 0;
}