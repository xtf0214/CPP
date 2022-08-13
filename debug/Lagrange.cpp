#include <cstdio>
#include <iostream>
using namespace std;
double function(int num, double x[], double y[], double a)
{
	double fund[num];
	for (int i = 0; i < num; i++)
	{
		double sum1 = 1, sum2 = 1;
		for (int j = 0; j < num; j++)
			if (i != j)
			{
				sum1 = sum1 * (x[i] - x[j]);
				sum2 = sum2 * (a - x[j]);
			}
		fund[i] = sum2 / sum1;
	}
	double p = 0;
	for (int i = 0; i < num; i++)
		p = p + y[i] * fund[i];
	printf("%f", p);
}
int main()
{
	cout << "输入节点的个数";
	int num;
	cin >> num;
	double x[num], y[num];
	for (int i = 0; i < num; i++)
	{
		cout << "输入第" << i + 1 << "个x的值";
		cin >> x[i];
		cout << "输入第" << i + 1 << "个y的值";
		cin >> y[i];
	}
	cout << "输入需要求解的值";
	double aa;
	cin >> aa;
	function(num, x, y, aa);
	return 0;
}
