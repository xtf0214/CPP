// 7-6 输出Fibonacci数列的前n项
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n;
    cin >> n;
    ll f[n + 1] = {0};
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    for (int i = 1; i <= n; i++)
    {
        printf("%-10d", f[i]);
        if (i % 4 == 0)
            printf("\n");
    }
    return 0;
}