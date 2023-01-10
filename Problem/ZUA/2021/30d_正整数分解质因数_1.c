#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; i++)
        while (i != n)
        {
            if (n % i == 0)
            {
                printf("%d*", i);
                n = n / i;
            }
            else
                break; //跳出while使i+1
        }
    printf("%d\n", n); //打印最后一个质因数，即i于n是的那个
    return 0;
}
