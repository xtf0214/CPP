#include <iostream>
using namespace std;
int a[1000005];
int left_bound(int a[], int n, int k)
{
    int l = 0, r = n;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (a[m] >= k)
            r = m;
        else if (a[m] < k)
            l = m + 1;
    }
    return a[l] == k ? l + 1 : -1;
}
int main()
{
    int m, n, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--)
    {
        cin >> x;
        cout << left_bound(a, n, x) << " ";
    }
    return 0;
}