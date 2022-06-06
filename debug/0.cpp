#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 5;

int main()
{
    int a[5] = {0, 1, 2, 3, 4};
    int n = 5, m = 2;
    // for (int i = n - m; i < 2 * n - m; i++)
    //     cout << a[i % n] << " ";
    int y = 0, x = 0;
    int b[n][n];
    bool rightarrow = true, downarrow = true;
    for (int i = 0; i < 4 * (n - 1); i++)
    {
        if (x % (n - 1) == 0 && y % (n - 1) == 0)
        {
            rightarrow = y & x ? false : true;
            downarrow = x ? false : true;
        }
        b[y][x] = i;
        cout << y << " " << x << endl;
        if (y % (n - 1) == 0)
            rightarrow ? x++ : x--;
        if (x % (n - 1) == 0)
            downarrow ? y++ : y--;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " \n"[j == n - 1];
    return 0;
}