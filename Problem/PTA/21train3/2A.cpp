#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll pow(ll x, ll n)
{
    ll s = 1;
    for (; n; n >>= 1, x = x * x)
        if (n & 1)
            s = s * x;
    return s;
}
int main()
{
    ll a, b;
    while(cin >> a >> b)
        cout << pow(a, b) << endl;
    return 0;
}