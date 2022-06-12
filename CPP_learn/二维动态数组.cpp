#include <iostream>
using namespace std;
int main()
{
    int m = 4, n = 5;
    int **A = new int *[m];
    for (int i = 0; i < m; i++)
        A[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = i + j, cout << A[i][j] << " \n"[j==n-1];
    int *B = new int[n];
    delete[] B;
}
