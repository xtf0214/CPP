#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, s = 0;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
        s += i;
    printf("sum = %d", s);
    return 0;
}