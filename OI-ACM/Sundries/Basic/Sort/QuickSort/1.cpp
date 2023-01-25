#include <iostream>
using namespace std;
int a[1005], n;

int partition(int l, int r) {
    int i = l, j = r - 1, pivot = a[l];
    while (i < j) {
        while (a[j] >= pivot && i < j)
            j--;
        while (a[i] <= pivot && i < j)
            i++;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[l]);
    return i;
}
void quickSelect(int l, int r) {
    if (r - l <= 1) return;
    int k = partition(l, r);
    quickSelect(l, k);
    quickSelect(k + 1, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSelect(0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}