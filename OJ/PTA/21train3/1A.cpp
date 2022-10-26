#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int mod = 114514;

int main()
{
    ll n;
    cin >> n;
    vi f{0, 1, 2, 4};
    if (n < 4)
        return cout << f[n], 0;
    for (ll i = 4; i <= n; i++)
    {
        for (int i = 0; i < 3; i++)
            f[i] = f[i + 1];
        f[3] = (f[2] + f[1] + f[0]) % mod;
    }
    cout << f[3] << endl;
    return 0;
}