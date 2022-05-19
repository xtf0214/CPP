#include <stdio.h>
int Sum(int x)
{
    int a = x % 10;
    int b = x / 10 % 10;
    int c = x / 100 % 10;
    return a + b + c;
}
int main()
{
    int n, ret;
    scanf("%d", &n);
    ret = Sum(n);
    printf("%d", ret);
    return 0;
}