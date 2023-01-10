// 7-45 猴子选大王
#include <stdio.h>
int main()
{
	int N, i, count = 0, k = 0, flag = 0;
	scanf("%d", &N);
	int n[N];
	for (i = 0; i < N; i++)
		n[i] = 1;
	while (k != N - 1)
		for (i = 0; i < N; i++)
			if (n[i] == 1)
			{
				flag = i;
				count++;
				if (count == 3)
				{
					n[i] = 0;
					k++;
					count = 0;
				}
			}
	printf("%d", flag + 1);
	return 0;
}