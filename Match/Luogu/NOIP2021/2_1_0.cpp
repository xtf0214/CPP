#include <bits/stdc++.h>
using namespace std;
// 1 <= K <= n <= 30    0 <= m <= 100
// 1 <= v[i] < 9982443531 v[0,1,...,m]
// 0 <= a[i] <= m a[1,2,...,n]
// x[i]=num(a_k == i) -> 0 <= x <= n
// x[a[i]] -> x[0,1,...,m]
// pows[i][j]=pow(v[i],j)
const int mod = 998244353;
int M, N, K;
long long c[35][35], pows[105][35], ans;
int v[105], x[105];
//生成满足[0,m)项的和为n的数列{x_i}
void dfs(int k, int n, long long s, long long t)
{
    if (k == 0)
    {
        x[k] = n;
        s += x[k] << k;
        t *= pows[k][x[k]] % mod * c[n][x[k]] % mod;
        if (__builtin_popcountll(s) <= K)
            ans = (ans + t) % mod;
        return;
    }
    for (int i = 0; i <= n; i++)
    {
        x[k] = i;
        dfs(k - 1, n - i, s + ((long long)x[k] << k), t * pows[k][x[k]] % mod * c[n][x[k]] % mod);
    }
}
int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i <= N; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
    for (int i = 0; i <= M; i++)
    {
        cin >> v[i];
        pows[i][0] = 1;
        for (int j = 1; j <= N; j++)
            pows[i][j] = pows[i][j - 1] * v[i] % mod;
    }
    dfs(M, N, 0, 1);
    cout << ans << endl;
    return 0;
}
