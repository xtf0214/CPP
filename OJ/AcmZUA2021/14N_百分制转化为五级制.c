#include <stdio.h>
int main(void)
{
    int a, i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a >= 90)
            printf("优秀\n");
        else if (80 <= a && a < 90)
            printf("良\n");
        else if (70 <= a && a < 80)
            printf("中\n");
        else if (60 <= a && a < 70)
            printf("及格\n");
        else
            printf("不及格\n");
    }
    return 0;
}
