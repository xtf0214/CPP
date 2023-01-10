#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    if (a > b)
        b += 7;
    cout << b - a << endl;
    return 0;
}