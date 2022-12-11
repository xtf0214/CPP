#include <iostream>
using namespace std;
int a[1005], n;

void inplaceMerge(int l, int m, int r) {
    int n1 = m - l, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + i];
    for (int k = l, i = 0, j = 0; k < r; k++)
        if ((j >= n2) || (i < n1 && L[i] <= R[j]))
            a[k] = L[i++];
        else // if ((i >= n1) || (j < n2 && L[i] > R[j]))
            a[k] = R[j++];
}
void MergeSort(int l, int r) {
    if (r - l <= 1)
        return;
    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m, r);
    inplaceMerge(l, m, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    MergeSort(0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
