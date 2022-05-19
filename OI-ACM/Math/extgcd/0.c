#include <stdio.h>
int main()
{
    int p, q;
    int A[100] = {0}, quotient[100] = {0}, n = 0;
    scanf("%d %d", &p, &q);
    while (q != 0)
    {
        int r = p % q;
        quotient[n++] = p / q;
        p = q;
        q = r;
    }
    A[n] = 0;     // y = 0
    A[n + 1] = 1; // x = 1
    for (int i = n - 1; i >= 0; i--)
    {
        A[i] = A[i + 2] - A[i + 1] * quotient[i];
        //printf("%d  %d\n", quotient[i], A[i]);
    }
    printf("%d %d", A[1], A[0]);
    return 0;
}
