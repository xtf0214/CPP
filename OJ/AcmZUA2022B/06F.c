// 1017 Problem  F	开灯问题（第二讲）
#include <stdio.h>
#define MAX 10000 + 5
int main()
{
    int n, k;
    int a[MAX] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++)
        for (int j = i; j <= n; j += i)
            a[j] ^= 1;
    for (int i = 1; i <= n; i++)
        if (a[i])
            printf("%d ",i);
    return 0;
}