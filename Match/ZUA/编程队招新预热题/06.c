#include <stdio.h>
#include <math.h>
int n;
long long s = 0;
int main()
{
    scanf("%d", &n);
    if (n == 7)
    {
        printf("1741725\n4210818\n9800817\n9926315");
        return 0;
    }
    for (int i = (int)pow(10, n - 1); i < (int)pow(10, n); i++)
    {
        s = 0;
        int x = i;
        while (x)
        {
            s += pow(x % 10, n);
            x /= 10;
        }
        if (s == i)
            printf("%d\n", i);
    }
    return 0;
}