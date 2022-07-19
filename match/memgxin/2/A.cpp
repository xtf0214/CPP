// 妙手
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a == 1 && b == 1)
    {
        puts("No");
        return 0;
    }
    if (__gcd(a, b) == 1)
        puts("Yes");
    else
        puts("No");
}
