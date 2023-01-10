#include <stdio.h>
int main()
{
    int num = 0, flag = 0, x;
    while (scanf("%d", &x) == 1)
    {
        if (flag == 0)
            num++;
        if (x == 250)
            flag = 1;
    }
    printf("%d", num);
    return 0;
}