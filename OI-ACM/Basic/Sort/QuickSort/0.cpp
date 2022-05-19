#include <iostream>
using namespace std;
int a[1005], n;
void Partition(int l, int r)
{
    if (r - l <= 1)
        return;
    int t = a[l], i = l;
    for (int j = l + 1; j < r; j++)
        if (a[j] <= t)
            swap(a[++i], a[j]);
    swap(a[i], a[l]);
    Partition(l, i);
    Partition(i + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Partition(0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}