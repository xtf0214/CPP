#include <stdio.h>
int main()
{
    int n;
    char book[10][50];
    int low1 = -1, high1 = -1;
    double low2 = 1 << 16, high2 = 0, price;
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
        if (price < low2)
        {
            low2 = price;
            low1 = i;
        }
    }
    printf("highest price: %.1f, %s\n", high2, book[high1]);
    printf("lowest price: %.1f, %s\n", low2, book[low1]);
    return 0;
}
/* 3
Programming in C
21.5
Programming in VB
18.5
Programming in Delphi
25 */