#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 5;
int main()
{
    int T, x;
    cin >> T;
    while (T--)
    {
        // 2,8,8,18,18,32,32
        cin >> x;
        if (x <= 2)
            cout << 1 << endl;
        else if (x <= 2 + 8)
            cout << 2 << endl;
        else if (x <= 2 + 8 + 8)
            cout << 3 << endl;
        else if (x <= 2 + 8 + 8 + 18)
            cout << 4 << endl;
        else if (x <= 2 + 8 + 8 + 18 + 18)
            cout << 5 << endl;
        else if (x <= 2 + 8 + 8 + 18 + 18 + 32)
            cout << 6 << endl;
        else if (x <= 2 + 8 + 8 + 18 + 18 + 32 + 32)
            cout << 7 << endl;
    }
    return 0;
}