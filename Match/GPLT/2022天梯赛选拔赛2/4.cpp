#include <iostream>
using namespace std;
int main()
{
	int sum = 0, k = 1, n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		k *= i;
		sum += k;
	}
	cout << sum;
}
