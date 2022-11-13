// P1036 [NOIP2002 普及组] 选数
// https://www.luogu.com.cn/problem/P1036
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define lowbit(x) x &(-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int n, m, ans;
vi a;
bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x != 1;
}
// d:当前要挑选的数,chs:前d个数里选择的个数,s:前d个数里选择的数的总和
void dfs(int d, int chs, int s)
{
    if (chs > m)
        return;
    if (chs + n - d < m) // n-d 剩余可挑选的数的个数
        return;
    if (d >= n)
    {
        if (isPrime(s))
            ans++;
        return;
    }
    dfs(d + 1, chs, s);            //不选
    dfs(d + 1, chs + 1, s + a[d]); //选
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    a = vi(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}