#include <cstdio>
#include <iostream>
using namespace std;
void cStyle() {
    int m = 4, n = 5;
    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        A[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            A[i][j] = i + j, printf("%d ", A[i][j]);
        printf("\n");
    }
}
void cppStyle() {
    int m = 4, n = 5;
    int **A = new int *[m];
    for (int i = 0; i < m; i++)
        A[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = i + j, cout << A[i][j] << " \n"[j == n - 1];
    int *B = new int[n];
    delete[] B;
}
int main() {
    cStyle();
    cout << '\n';
    cppStyle();
}
