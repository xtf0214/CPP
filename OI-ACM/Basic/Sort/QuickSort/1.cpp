#include <iostream>
using namespace std;
int a[1000005], n;
void QuickSort(int l, int r)
{
    if (r - l <= 1)
        return;
    swap(a[l], a[(l + r) / 2]);
    int i = l, j = r - 1, t = a[l];
    while (i < j)
    {
        while (a[j] >= t && i < j)
            j--;
        while (a[i] <= t && i < j)
            i++;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[l]);
    QuickSort(l, i);
    QuickSort(i + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    QuickSort(0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}