#include <stdio.h>
int sum_odd(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 1)
            s += a[i];
    return s;
}
int main()
{
    int num[7];
    int k, ret;
    for (k = 0; k < 7; k++)
        scanf("%d", &num[k]);
    ret = sum_odd(num, 7);
    printf("%d", ret);
    return 0;
}