#include <bits/stdc++.h>
using namespace std;

int n, a[100002];

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
		
	for (int j = n - 2; ;j--)
		if (isprime(a[j] - 2)) {
			idx = j + 1;
			break;
		}
	for (int j = idx, i = 1; j <= n; j++, i++)
		swap(a[i], a[j]);
	}
	//ou
//	printf("ou : %d\n", ou);
	if (!isprime(a[ou] - 1)) {
		
	for (int j = ou - 2; ; j--) {
		if (isprime(a[j] - 1)) {
			idx = j + 1;
//			printf("----%d\n", j);
			break;
		}
	}
//	if (isprime(69))
//		printf("---\n");
	for (int i = idx, j = ou + 1; i <= ou; i++, j++)
		swap(a[i], a[j]);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	cout << endl;
	
//	bool ok = true;
//		for(int i=0;i<n;i++) {
//			int j = (i + 1) % n;
//			
//			if (!isprime(abs(a[i+1] - a[j+1])))
//				ok = false;
//		}
//		if(ok) puts("AC");
	return 0;
}
