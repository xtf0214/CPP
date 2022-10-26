#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int a[7] = {0};
    int n, s = 0;
    cin >> n;
    for (int i = 0, x, y; i < n; i++)
    {
        cin >> x >> y;
        s += y;
        a[x] += y;
    }
    for (int i = 1; i <= 6; i++)
        i == 1 ? (cout << a[i] * 6 - s) : (cout << " " << a[i] * 6 - s);
    return 0;
}