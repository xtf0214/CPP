#include <bits/stdc++.h>
using namespace std;
bool not_prime[200000005];
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            for (int j = i; j <= n; j += i)
                not_prime[j] = 1;
            int t = n / i;
            for (int j = t; j <= n; j += t)
                not_prime[j] = 1;
        }
    for (int i = 1; i <= n; i++)
        cnt += not_prime[i];
    cout << n - cnt;
    return 0;
}