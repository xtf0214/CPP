#include <bits/stdc++.h>
using namespace std;

int quickSelect(int a[], int l, int r, int k) // 0-st
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
        return quickSelect(a, i + 1, r, k);
    else
        return quickSelect(a, l, i, k);
}
int main()
{
    int T, m, k;
    cin >> T >> m >> k;
    int a[m];
    while (T--)
    {
        for (int i = 0; i < m; i++)
            cin >> a[i];
        cout << quickSelect(a, 0, m, k - 1) << endl;
    }
    return 0;
}