#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll x, ll n)
{
    ll s = 1;
    for (; n; n >>= 1, x = x * x)
        if (n & 1)
            s = s * x;
    return s;
}
ll pow_mod(ll x, ll n, ll m)
{
    ll s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return s;
}
int main()
{
    return 0;
}