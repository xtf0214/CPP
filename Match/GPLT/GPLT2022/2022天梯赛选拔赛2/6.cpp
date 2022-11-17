// 7-6 查验身份证
#include <bits/stdc++.h>
using namespace std;
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char z[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
	int n;
	cin >> n;
	string s;
	bool flag0 = true;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int sum = 0;
		bool flag = true;
		for (int j = 0; j < 17; j++)
		{
			if (s[j] > '9' || s[j] < '0')
			{
				flag = false;
				break;
			}
			sum += (s[j] - '0') * weight[j] % 11;
		}
		sum %= 11;
		if (z[sum] != s[17])
			flag = false;
		if (!flag)
		{
			cout << s << endl;
			flag0 = false;
		}
	}
	if (flag0)
		cout << "All passed";
	return 0;
}
