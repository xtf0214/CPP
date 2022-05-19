#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n / 2; i++)
		s1 += a[i];
	for (int i = n / 2; i < n; i++)
		s2 += a[i];
	printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d", n - n / 2, n / 2, s2 - s1);
}
