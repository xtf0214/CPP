#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Book
{
    string name;
    double price;
} book[10];

bool cmp(const Book &a, const Book &b) { return a.price < b.price; }

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, book[i].name);
        scanf("%lf\n", &book[i].price);
    }
    sort(book, book + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << book[i].name;
        printf(" %.1lf\n", book[i].price);
    }
    return 0;
}
