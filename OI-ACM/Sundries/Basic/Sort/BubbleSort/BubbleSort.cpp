#include <iostream>
using namespace std;
int cut = 0;
void BubbleSort(int *A, int n)
{
    for (int i = 1; i <= n - 1; i++)
        for (int j = n - 1; j >= i; j--)
            if (A[j] < A[j - 1])
                swap(A[j], A[j - 1]), cut++;
}