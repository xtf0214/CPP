#include <stdio.h>
void turn(int a[], int n)
{
    int *p = a + n - 1;
    for (; a < p; a++, p--)
        *a = *a + *p, *p = *a - *p, *a = *a - *p;
}
int main()
{
    int n;
    int num[1000];
    int k;
    scanf("%d", &n);
    for (k = 0; k < n; k++)
        scanf("%d", &num[k]);
    turn(num, n);
    for (k = 0; k < n; k++)
        printf("%d ", num[k]);
    return 0;
}