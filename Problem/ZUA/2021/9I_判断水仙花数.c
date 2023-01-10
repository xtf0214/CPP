#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a = n % 10, b = n / 10 % 10, c = n / 100 % 10;
    if (n == a * a * a + b * b * b + c * c * c)
        printf("Yes");
    else
        printf("No");
    return 0;
}