#include <bits/stdc++.h>
using namespace std;

int maxElement(int a[],int l,int r)
{
    if(r-l<=1)
        return a[l];
    int m = (l + r) / 2;
    return max(maxElement(a, l, m), maxElement(a, m, r));
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];
    cout << maxElement(a, 0, n) << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
