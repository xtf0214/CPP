#include <iostream>
using namespace std;
int main()
{
    int L[5] = {3, 4, 5, 6, 7}, R[5] = {1, 2, 3, 4, 5};
    int m = sizeof(L) / sizeof(L[0]);
    int n = sizeof(R) / sizeof(R[0]);
    int A[10] = {0};
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while (i < m)
        A[k++] = L[i++];
    while (j < n)
        A[k++] = R[j++];
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
}