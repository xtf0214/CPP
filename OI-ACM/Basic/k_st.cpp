#include <iostream>
using namespace std;
int QuickSelect(int a[], int l, int r, int k)
{
    if (r - l <= 1)
        return a[l];
    int i = l, j = r - 1, tmp = a[l];
    while (i < j)
    {
        while (i < j && a[j] >= tmp)
            j--;
        while (i < j && a[i] <= tmp)
            i++;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[l]);
    if (i == k)
        return a[i];
    else if (i < k)
        return QuickSelect(a, i + 1, r, k);
    else
        return QuickSelect(a, l, i, k);
}
int main()
{
    // for a in orderly array unique
    int n = 10;
    int arr[n]{3, 2, 5, 7, 1, 9, 4, 0, 8, 6};
    cout << QuickSelect(arr, 0, 10, 3);
    return 0;
}