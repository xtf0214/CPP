#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z;
    long long l, r;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        l = x * x + y * y + z * z;
        r = 3 * x * y * z;
        if (l == r)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}