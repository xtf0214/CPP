#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        cin >> x;
        cout << a[x] << endl;
    }
    return 0;
}