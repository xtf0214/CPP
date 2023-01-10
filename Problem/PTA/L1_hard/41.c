// 7-41 二分法求多项式单根
#include <stdio.h>
#include <math.h>
float a0, a1, a2, a3;
float f(float x) { return a3 * x * x * x + a2 * x * x + a1 * x + a0; }
int main()
{
	float a, b;
	scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
	scanf("%f %f", &a, &b);
	float mid;
	while (b - a > 0.0001)
	{
		if (f(a) == 0)
		{
			printf("%.2f", a);
			return 0;
		}
		if (f(b) == 0)
		{
			printf("%.2f", b);
			return 0;
		}
		mid = (a + b) / 2;
		if (f(mid) * f(a) > 0)
			a = mid;
		else
			b = mid;
	}
	printf("%.2f", mid);
	return 0;
}