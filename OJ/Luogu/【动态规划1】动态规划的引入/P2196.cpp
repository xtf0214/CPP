// 	[NOIP1996 提高组] 挖地雷
// https://www.luogu.com.cn/problem/P2196
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
#define all(v) v.begin(), v.end()
#define fi first
#define se second
template <typename T>
void print(T &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " \n"[i == v.size() - 1];
}
template <typename T>
void print(T *bg, T *ed)
{
    for (T *it = bg; it != ed; it++)
        cout << *it << " \n"[it == ed - 1];
}
const int N = 1e3 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int n, a[N], cost[N][N], pre[N];
int dp[N];
void solve()
{
    for (int v = 1; v <= n; v++)
    {
        dp[v] = a[v];
        for (int u = 1; u < v; u++)
            if (cost[u][v])
                if (dp[v] < dp[u] + a[v])
                {
                    dp[v] = dp[u] + a[v];
                    pre[v] = u;
                }
    }
}
void printPath(int k)
{
    if (k == 0)
        return;
    printPath(pre[k]);
    cout << k << " ";
}
int main()
{
    // ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> cost[i][j];
    solve();
    // print(dp + 1, dp + n + 1);
    printPath(max_element(dp + 1, dp + n + 1) - dp);
    cout << endl;
    cout << *max_element(dp + 1, dp + n + 1) << endl;
    return 0;
}