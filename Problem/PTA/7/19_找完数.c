#include <stdio.h>
void BubbleSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (A[j] < A[j - 1])
            {
                int t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
            }
}
int main()
{
    int m, n, flag = 0;
    scanf("%d %d", &m, &n);
    for (int x = m; x <= n; x++)
    {
        int n = 1, s = 0;
        int A[100] = {1};
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
            {
                A[n++] = i;
                if (i * i != x)
                    A[n++] = x / i;
            }
        BubbleSort(A, n);
        for (int i = 0; i < n; i++)
            s += A[i];
        if (s == x)
        {
            flag = 1;
            printf("%d = ", x);
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                    printf("%d", A[i]);
                else
                    printf("%d + ", A[i]);
            }
            printf("\n");
        }
    }
    if (!flag)
        printf("None");
    return 0;
}