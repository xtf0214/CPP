#include <iostream>
using namespace std;
int t[1001], m;
void dfs(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << t[i] << " "[i == m - 1];
		return;
	}
	t[k] = 0;
	dfs(k + 1);
	t[k] = 1;
	dfs(k + 1);
	return;
}
int main()
{
	cin >> m;
	dfs(0);
	return 0;
}
