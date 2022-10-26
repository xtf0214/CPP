#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	char c;
	cin >> n >> c;
	for (int i = 0; i < (int)floor(n * 0.5 + 0.5); i++)
	{
		for (int j = 0; j < n; j++)
			cout << c;
		cout << endl;
	}
	return 0;
}
