#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    cout << a[n - 1] << endl;
    return 0;
}