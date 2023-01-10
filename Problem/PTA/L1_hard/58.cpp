// 7-58 输出全排列
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> num(10);
vector<int> arr(10);
void dfs(int step)
{
	int i;
	if (step == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << num[i];
		}
		cout << endl;
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			num[step] = i;
			arr[i] = 1;
			dfs(step + 1);
			arr[i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	dfs(1);
}