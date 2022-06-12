// 7-3 输入书籍信息
#include <stdio.h>
struct Book
{
    char name[50];
    double price;
} book[10];
int main()
{
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", book[i].name);
        scanf("%lf", &(book[i].price));
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s ", book[i].name);
        printf("%.1lf\n", book[i].price);
    }
    return 0;
}