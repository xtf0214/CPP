#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s = 0, n, k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        k *= i;
        s += k;
    }
    cout << s;
    return 0;
}