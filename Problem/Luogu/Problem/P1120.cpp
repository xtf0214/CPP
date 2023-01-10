// P1120 小木棍
// https://www.luogu.com.cn/problem/P1120
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T>
using vT = vector<T>;
template <typename T>
using vvT = vector<vector<T>>;
#define vvTy(Ty, n, m, k) vvT<Ty>(n, vT<Ty>(m, k))
#define y first
#define x second
#define all(v) v.begin(), v.end()
#define lowbit(x) (x & (-x))
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
       
int n, d, ans;
vT<bool> vis;
vT<int> a;
void dfs(int u, int k)
{
    if (u == 0)
        return dfs(d, k - 1);
    if (k == 0)
    {
        printf("%d\n", ans);
        exit(0);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i] && a[i] <= u)
            dfs(u - a[i], k);
}
signed main()
{
    return 0;
}