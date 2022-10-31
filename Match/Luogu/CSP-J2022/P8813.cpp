#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow(ll x, ll n)
{
    ll s = 1;
    for (; n; n >>= 1, x = x * x)
        if (n & 1)
        {
            s = s * x;
            if (s > int(1e9))
                return -1;
        }
    return s;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << pow(a, b);
    return 0;
}