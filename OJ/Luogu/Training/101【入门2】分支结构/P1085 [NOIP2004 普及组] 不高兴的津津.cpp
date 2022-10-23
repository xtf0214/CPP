#include <iostream>
using namespace std;
int main()
{
	int i = 0, s[10], m = 0, a, b;
	for (i = 0; i < 7; i++)
	{
		s[i] = 0;
		cin >> a >> b;
		s[i] = a + b;
	}
	for (i = 0; i < 7; i++)
	{
		if (s[i] > 8)
		{
			cout << i + 1 << " ";
			m++;
			break;
		}
	}
	if (m == 0)
		cout << m;
	return 0;
}