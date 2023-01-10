// 1027 Problem  K	用分治法寻找最大值（第三讲）
#include <bits/stdc++.h>
using namespace std;

int minElement(int a[], int l, int r)
{
    if (r - l <= 1)
        return a[l];
    int m = (l + r) / 2;
    int ml = minElement(a, l, m);
    int mr = minElement(a, m, r);
    return max(ml, mr);
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << minElement(a, 0, n) << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
