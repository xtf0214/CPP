#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int n, m, k;
ll v[105], c[35][35], p[105][35], f[105][35][35][35];
int count(ll x)
{
	int res = 0;
	while (x)
		res += x & 1, x >>= 1;
	return res;
} //统计x二进制中1的个数
ll dfs(int x, int y, int a, int b)
{
	if (y >= n)
		return a + count(b) <= k; //1的数量不超过k
	if (x > m)
		return 0; //序列不够n个数且不合法
	if (f[x][y][a][b] != -1)
		return f[x][y][a][b];
	ll res = 0;
	for (int i = 0; i <= n - y; i++)
		res = (res + dfs(x + 1, y + i, a + (b + i & 1), b + i >> 1) * p[x][i] % mod * c[n - y][i] % mod) % mod;
	//在剩下n-y个位置中放入i个2^x
	return f[x][y][a][b] = res; //记忆化
} //枚举到2^x，已用了y个数，a个低位1，b个高位1
int main()
{
	memset(f, -1, sizeof(f));
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	} //组合数
	for (int i = 0; i <= m; i++)
	{
		p[i][0] = 1;
		for (int j = 1; j <= n; j++)
			p[i][j] = p[i][j - 1] * v[i] % mod;
	} //v[i]^j
	printf("%lld\n", dfs(0, 0, 0, 0));
	return 0;
}
