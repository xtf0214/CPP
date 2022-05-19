#include <iostream>
using namespace std;
int main()
{
    int L[5] = {3, 4, 5, 6, 7}, R[5] = {1, 2, 3, 4, 5};
    int m = sizeof(L) / sizeof(L[0]);
    int n = sizeof(R) / sizeof(R[0]);
    int A[10] = {0};
    for (int k = 0, i = 0, j = 0; k < 10; k++)
    {
        if ((j >= n) || (i < m && L[i] <= R[j]))
            A[k] = L[i++];
        else //if ((i >= m) || (j < n && L[i] > R[j]))
            A[k] = R[j++];
    }
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
}