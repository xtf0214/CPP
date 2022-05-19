#include <iostream>
using namespace std;
int a[1000005];
int leftBound(int a[], int n, int k)
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
    if (l == n || a[l] != k)
        return -1;
    return l;
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
        cout << leftBound(a, n, x) << " ";
    }
    return 0;
}