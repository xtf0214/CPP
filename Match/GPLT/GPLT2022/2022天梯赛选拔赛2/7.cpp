// 7-7 N个数求和
#include <stdio.h>
#include <math.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main()
{
	int n;
	scanf("%d", &n);
	int a, b;
	int p = 0, q = 1; // 总和为 p/q
	for (int i = 0; i < n; i++)
	{
		scanf("%d/%d", &a, &b);
		p = p * b + q * a;
		q = q * b;
		int r = gcd(abs(p), abs(q));
		p /= r;
		q /= r;
	}
	if (q == 1)
		printf("%d", p);
	else if (p > q)
		printf("%d %d/%d", p / q, p % q, q);
	else
		printf("%d/%d", p, q);
	return 0;
}
