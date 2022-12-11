#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void partition(int *L, int *R) {
    if (R - L <= 1)
        return;
    int n = R - L;
    int i = 0, j = n - 1, pivot = L[0];
    while (i < j) {
        while (L[j] >= pivot && i < j)
            j--;
        while (L[i] <= pivot && i < j)
            i++;
        if (i < j)
            swap(L[i], L[j]);
    }
    swap(L[i], L[0]);
}
int main() {
    int n = 5;
    int a[n] = {3, 1, 2, 5, 7};
    partition(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}