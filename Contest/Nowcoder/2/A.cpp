// 妙手
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, m;
    cin >> n >> m;
    if ((n + m) % 2 && __gcd(n, m) == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}