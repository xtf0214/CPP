#include <bits/stdc++.h>
using namespace std;

int n, a[100002], b[100002];

bool isprime(int x) {
//	printf("x : %d\n", x);
	if (x == 0)
		return 0;
	if (x == 2)
		return 1;
	if (x == 1)
		return 0;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
//			printf("i : %d\n", i);
			return 0;
		}
	return 1;
}

int main() {
	cin >> n;
	if (n < 5) {
		printf("-1\n");
		return 0;
	}
	int ou = n / 2;
	for (int i = 1; i <= ou; i++)
		a[i] = i * 2;
	int ji = n - ou;
	for (int i = 1, j = ou + 1; i <= ji; i++, j++)
		a[j] = i * 2 - 1;
	int idx;
	if (!isprime(a[n] - 2)) {
		
		for (int j = n; ;j--)
			if (isprime(a[j] - 2) && isprime(a[j - 1] - 2)) {
				idx = j;
				break;
			}
		int p = n - idx + 1;
		int cnt = 0;
		for (int i = 1, j = idx; i <= p; i++, j++) {
			b[++cnt] = a[i];
			b[++cnt] = a[j];
		}
		for (int i = n - p + 1, j = 1; i <= n; i++, j++)
			a[i] = b[j];
		for (int i = 1, j = p + 1; i <= p; i++, j++)
			a[i] = b[j];
	}
	if (!isprime(a[ou] - 1)) {
		
		for (int j = ou; ; j--) {
			if (isprime(a[j] - 1) && isprime(a[j - 1] - 1)) {
				idx = j;
				break;
			}
		}
		int cnt = idx - 1, p = 0;
		for (int i = idx, j = ou + 1; i <= ou; i++, j++) {
			b[++cnt] = a[j];
			b[++cnt] = a[i];
			p += 2;
		}
		for (int i = idx; i <= idx + p - 1; i++)
			a[i] = b[i];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	cout << endl;
	return 0;
}
