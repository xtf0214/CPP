#include <stdio.h>

void dectobin(int n);

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}
void dectobin(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }
    int A[100], t = 0;
    while (n > 0)
    {
        A[t++] = n % 2;
        n /= 2;
    }
    for (int i = t - 1; i >= 0; i--)
        printf("%d", A[i]);
}