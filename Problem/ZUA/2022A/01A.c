#include <stdio.h>
int Sum(int x)
{
    return x % 10 + x / 10 % 10 + x / 100;
}
int main()
{
    int n, ret;
    scanf("%d", &n);
    ret = Sum(n);
    printf("%d", ret);
    return 0;
}