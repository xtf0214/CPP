#include <iostream>
using namespace std;
int a[1005], n, k;

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
int quickSelect(int l, int r, int k) {
    if (r - l <= 1)
        return;
    int i = partition(l, r);
    if (i == k)
        return a[i];
    else if (i < k)
        return quickSelect(i + 1, r, k);
    else
        return quickSelect(l, i, k);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quickSelect(0, n, k);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}