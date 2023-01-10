#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, cnt = 0, flag = 0, ans = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            for (cnt = 0; n % i == 0; n /= i)
                cnt++;
            if (cnt != 1)
                flag = 1;
            ans ^= cnt;
        }
    if (n > 1)
        ans ^= 1;
    if ((!flag && !ans) || (flag && ans))
        puts("Alice win");
    else
        puts("Bob win");
    return 0;
}
