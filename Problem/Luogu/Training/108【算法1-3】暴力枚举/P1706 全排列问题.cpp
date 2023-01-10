#include <iostream>
#include <cstdio>
using namespace std;
int A[1001], Book[1001], t[1001], n;
void Permutation(int step)
{
	if (step == n)
	{
		for (int i = 0; i < n; i++)
			printf("%5d", A[t[i]]);
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++)
		if (Book[i] == 0)
		{
			t[step] = i;
			Book[i] = 1;
			Permutation(step + 1);
			Book[i] = 0;
		}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		A[i] = i + 1;
	Permutation(0);
	return 0;
}
