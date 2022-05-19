#include <stdio.h>
#include <math.h>
int judge(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 1;
}
int main()
{
    int n, ret;
    scanf("%d", &n);
    ret = judge(n);
    printf("%d", ret);
    return 0;
}