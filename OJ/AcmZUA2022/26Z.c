#include <stdio.h>
#include <math.h>
int judge(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 1;
}
int sum_su(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (judge(a[i]))
            sum += a[i];
    return sum;
}
int main()
{
    int k, num[6];
    int ret;
    for (k = 0; k < 6; k++)
    {
        scanf("%d", &num[k]);
    }
    ret = sum_su(num, 6);
    printf("%d", ret);
    return 0;
}