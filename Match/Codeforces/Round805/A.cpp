#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int T, x, res, i;
    cin >> T;
    while (T--)
    {
        cin >> x;
        res = 0;
        for (i = 1; x >= 10; x /= 10, i *= 10)
            res += x % 10 * i;
        res += (x - 1) * i;
        cout << res << endl;
    }
    return 0;
}