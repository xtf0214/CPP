// 1042 Problem  Z	素数环问题（第五讲）
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (string[2]){"", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

bool isPrime[N];
bool vis[N];
void ertos(int n)
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            for (int j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
}
void dfs(int k, int n, vi &a)
{
    if (k == n)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (!isPrime[a[i] + a[(i + 1) % n]])
                flag = false;
        if (flag)
            print(a);
        return;
    }
    for (int i = 2; i <= n; i++)
        if (!vis[i])
        {
            vis[i] = true;
            a[k] = i;
            dfs(k + 1, n, a);
            vis[i] = false;
        }
}
int main()
{
    int n;
    ertos(N);
    while (cin >> n)
    {
        vi a(n);
        a[0] = 1;
        dfs(1, n, a);
    }
    return 0;
}