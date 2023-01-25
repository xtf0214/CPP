#include <stdio.h>
void InsectSort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > x)
            A[j + 1] = A[j], j--;
        A[j + 1] = x;
    }
}
int main()
{
    int A[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    InsectSort(A, n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}