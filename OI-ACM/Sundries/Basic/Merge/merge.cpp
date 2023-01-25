#include <bits/stdc++.h>
using namespace std;
void merge(int *L1, int *R1, int *L2, int *R2, int *res) {
    int m = R1 - L1, n = R2 - L2;
    for (int k = 0, i = 0, j = 0; k < m + n; k++)
        if ((j >= n) || (i < m && L1[i] <= L2[j]))
            res[k] = L1[i++];
        else // if ((i >= m) || (j < n && L[i] > R[j]))
            res[k] = L2[j++];
}
int main() {
    int L[5] = {1, 3, 5, 7, 9}, R[5] = {0, 2, 4, 6, 8};
    int m = 5, n = 5;
    int a[10];
    merge(L, L + m, R, R + n, a);
    for (int i = 0; i < m + n; i++)
        cout << a[i] << " ";
    return 0;
}
