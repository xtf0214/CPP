#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
bool broken[100005];
int ans[100005];
int T, n, k;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        memset(broken, 0, sizeof(broken));
        memset(ans, 0, sizeof(ans));
        ans[0] = 1;
        for (int j = 0, t; j < k; j++)
        {
            cin >> t;
            broken[j] = true;
        }
        for (int i = 1; i <= n; i++)
            if (!broken[i])
            {
                if (i == 1)
                    ans[i] = ans[i - 1] % MOD;
                else
                    ans[i] = (ans[i - 1] + ans[i - 2]) % MOD;
            }
        cout << ans[n] << endl;
    }
    return 0;
}