#include <iostream>
using namespace std;
// 1 <= K <= n <= 30    0 <= m <= 100
// 0 <= a[i] <= m  a[1,2,...,n]
// 1 <= v[i] < 9982443531  v[0,1,...,m]
const int mod = 998244353;
int m, n, K;
long long ans;
int v[105], a[35];
void dfs(int k, long long s, long long t)
{
    if (k == n + 1)
    {
        if (__builtin_popcountll(s) <= K)
            ans = (ans + t) % mod;
        return;
    }
    for (int i = 0; i <= m; i++)
    {
        a[k] = i;
        dfs(k + 1, s + (1 << a[k]), t * v[a[k]] % mod);
    }
}
int main()
{
    cin >> n >> m >> K;
    for (int i = 0; i <= m; i++)
        cin >> v[i];
    dfs(1, 0, 1);
    cout << ans << endl;
    return 0;
}
