// 7-58 输出全排列
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[10], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	do
	{
		for (int i = 0; i < n; i++)
			cout << a[i];
		cout << endl;
	} while (next_permutation(a, a + n));
	return 0;
}