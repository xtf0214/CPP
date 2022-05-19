#include <stdio.h>
int f(int x)
{
    return x % 2 == 0 ? 1 : 0;
}
int main()
{
    int n, ret;
    scanf("%d", &n);
    ret = f(n);
    printf("%d", ret);
    return 0;
}