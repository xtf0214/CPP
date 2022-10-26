#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const long long N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e11 + 3;
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    long long a = 3, b = 1,t, s[4]{0, 1, 4, 4};
    for (int i = 3; i <= n; i++)
    {
        t = (a + b) % mod;
        b = a;
        a = t;
        s[3] = (s[3] + t) % mod;
        cout << i << " " << a << " " << s[3] << endl;
    }
    if (n >= 3)
        cout << s[3] << endl;
    else
        cout << s[n] << endl;
    return 0;
}