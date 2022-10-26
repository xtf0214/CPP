#include <bits/stdc++.h>
using namespace std;
int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int y, m, d, s = 0;
    scanf("%d/%d/%d", &y, &m, &d);
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        Month[2]++;
    for (int i = 1; i < m; i++)
        s += Month[i];
    s += d;
    cout << s;
    return 0;
}