#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    ll ans = 0;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        scanf("%ld", a + i);
    for (int i = 1; i < (1 << n); i++)
    {
        ll mul = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                mul ^= a[j];
        if (mul > ans)
            ans = mul;
    }
    cout << ans;
}