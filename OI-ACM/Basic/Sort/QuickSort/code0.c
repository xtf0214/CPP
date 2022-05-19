#include <stdio.h>
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void QuickSort(int *A, int left, int right)
{
    if (right - left <= 1)
        return;
    Swap(&A[left], &A[(left + right) / 2]);
    int i = left, j = right - 1, t = A[left];
    while (i < j)
    {
        while (A[j] >= t && i < j)
            j--;
        while (A[i] <= t && i < j)
            i++;
        if (i < j)
            Swap(&A[i], &A[j]);
    }
    Swap(&A[i], &A[left]);
    QuickSort(A, left, i);
    QuickSort(A, i + 1, right);
}
int main()
{
    int n, A[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    QuickSort(A, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}