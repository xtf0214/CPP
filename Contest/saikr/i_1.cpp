#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
typedef long long ll;
ll arr[MAX];
ll p[MAX];

void Get_LB(ll x)
{
    for (int i = 62; i >= 0; --i)
    {
        if (!(x >> (ll)i))
            continue;
        if (!p[i])
        {
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        Get_LB(arr[i]);
    }
    long long ans = 0;
    for (int i = 62; i >= 0; --i)
    {
        if ((ans ^ p[i]) > ans)
            ans ^= p[i];
    }
    cout << ans << endl;

    return 0;
}
