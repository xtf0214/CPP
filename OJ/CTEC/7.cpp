#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0, c = 0;
		char d;
		while ((d = getchar()) != '\n')
		{
			if ('a' <= d && d <= 'z' || 'A' <= d && d <= 'Z')
				a++;
			else if ('0' <= d && d <= '9')
				b++;
			else
				c++;
		}
		printf("%d %d %d\n", a, b, c);
	}
	return 0;
}
