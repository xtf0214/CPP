#include <bits/stdc++.h>
using namespace std;
void inplaceMerge(int *l, int *m, int *r) {
    int n1 = m - l, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = l[i];
    for (int i = 0; i < n2; i++)
        R[i] = m[i];
    for (int k = 0, i = 0, j = 0; k < n1 + n2; k++)
        if ((j >= n2) || (i < n1 && L[i] <= R[j]))
            l[k] = L[i++];
        else // if ((i >= n1) || (j < n2 && L[i] > R[j]))
            l[k] = R[j++];
}
int main() {
    int n = 10;
    int a[n]{1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    inplaceMerge(a, a + 5, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
