#include <iostream>
using namespace std;
int a[1001], book[1001], t[1001];
int num[1001]; //
void combine(int k, int m, int n, int st)
{
	num[k]++;	   //每个层调用次数
	bool first = true; //是否第一次调用决定缩减
	if (k == 0)
	{
		printf("%d_%d_%d", k, n - st, num[k]); //打印信息
		cout << endl
			 << "    ";
		return;
	}

	// for (int i = st; i < n; i++)
	for (int i = st; i <= n - k; i++)
		if (book[i] == 0)
		{
			t[k] = i;
			book[i] = 1;
			if (!first) //若非第一次调用,缩进
				for (int i = m; i > k; i--)
					cout << "           ";
			printf("%d_%d_%d---|%d|", k, n - st, num[k], i); //打印信息
			combine(k - 1, m, n, i + 1);
			first = false; //第一次调用结束
			book[i] = 0;
		}
	cout << endl
		 << "    "; //分层
}
int main()
{
	// int m, n;
	// cin >> n >> m;
	// for (int i = 0; i < n; i++)
	// 	cin >> a[i];
	combine(6, 6, 8, 0);
	return 0;
}
