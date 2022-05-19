#include <iostream>
using namespace std;
int a[1001], book[1001], t[1001];
void combine(int k, int m, int n, int st)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << t[i] << " ";
		cout << endl;
		return;
	}
	for (int i = st; i <= n - m + k; i++)
	// for (int i = st; i < n; i++)
		if (!book[i])
		{
			t[k] = i;
			book[i] = 1;
			combine(k + 1, m, n, i + 1);
			book[i] = 0;
		}
}
int main()
{
	// int m, n;
	// cin >> n >> m;
	// for (int i = 0; i < n; i++)
	// 	cin >> a[i];
	combine(0, 2, 4, 0);
	return 0;
}
