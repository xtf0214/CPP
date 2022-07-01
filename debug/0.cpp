#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
const int MAX = 10000 + 5;
int main()
{
    int a[9][9] = {0};
    // for (int i = 0; i < 50; i++)
    //     cout << lowbit(i) << endl;
    for (int i = 1; i <= 8; i++)
        for (int j = i; j <= 8; j += lowbit(j))
            a[i][j]++;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            cout << a[i][j] << " \n"[j == 8];
    return 0;
}