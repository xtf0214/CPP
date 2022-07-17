#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000 + 5;
int main()
{
    long long n, cnt = 0;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            cnt++;
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        cnt++;
    if (cnt % 2)
        cout << "Bob win";
    else
        cout << "Alice win";
    return 0;
}
