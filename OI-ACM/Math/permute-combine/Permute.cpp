#include <iostream>
using namespace std;
int a[1001], book[1001], t[1001];
void permute(int k, int m, int n)
{
	if (k == 0)
	{
		for (int i = 0; i < m; i++)
			cout << t[i] << " \n"[i == m - 1];
		return;
	}
	for (int i = 0; i < n; i++)
		if (book[i] == 0)
		{
			t[k] = i;
			book[i] = 1;
			permute(k - 1, m, n);
			book[i] = 0;
		}
}
int main()
{
	// int m, n;
	// cin >> n >> m;
	// for (int i = 0; i < n; i++)
	// 	cin >> a[i];
	permute(3, 3, 4);
	return 0;
}
