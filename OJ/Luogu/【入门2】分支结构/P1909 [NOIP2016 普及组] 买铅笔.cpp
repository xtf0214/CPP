#include <iostream>
using namespace std;
int main()
{
	int piece, money;
	int i, s, n, min;
	cin >> n;
	for (i = 1; i <= 3; i++)
	{
		cin >> piece >> money;
		s = (n % piece == 0) ? n / piece * money
							 : (n / piece + 1) * money;
		if (i == 1)
			min = s;
		min = (s < min) ? s : min;
	}
	cout << min;
	return 0;
}