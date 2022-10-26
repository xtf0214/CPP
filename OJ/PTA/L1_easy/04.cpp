// 7-4 书籍排序
#include <iostream>
#include <algorithm>
using namespace std;
struct Book
{
    char name[50];
    double price;
} book[10];

bool cmp(const Book &a, const Book &b) { return a.price < b.price; }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %[^\n]", book[i].name);
        scanf("%lf", &book[i].price);
        cin.get();
    }
    sort(book, book + n, cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%s ", book[i].name);
        printf("%.1lf\n", book[i].price);
    }
    return 0;
}