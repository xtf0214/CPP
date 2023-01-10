#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    ll a, b, p;
    cin >> a >> b >> p;
    printf("%d^%d mod %d=%d", a, b, p, pow_mod(a, b, p));
    return 0;
}