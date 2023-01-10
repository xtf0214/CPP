// 7-5 查找单价最高的书
#include <stdio.h>
int main()
{
    int n;
    char book[10][50];
    int  high1 = -1;
    double  high2 = 0, price;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", book[i]);
        scanf("%lf", &price);
        if (price > high2)
        {
            high2 = price;
            high1 = i;
        }
    }
    printf("highest price: %.1f, %s\n", high2, book[high1]);
    return 0;
}