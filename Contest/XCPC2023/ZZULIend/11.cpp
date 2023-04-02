#include <bits/stdc++.h>
using namespace std;

string x1, ys, x2, y2;
int ok1 = 1, ok2 = 1;
long long ss1, ss2;

long long check(long long x, long long y) {
	return x * x + y * y;
}

int main() {
	cin >> x1 >> ys >> x2 >> y2;
	if (x1.size() <= 5 && ys.size() <= 5) {
		int xx1 = stoi(x1);
		int yy1 = stoi(ys);
		ss1 = check(1LL * xx1, 1LL * yy1);
		if (ss1 <= 1000 * 1000)
			;
		else
			ok1 = 0;
	} else {
		ok1 = 0;
	}
	if (x2.size() <= 5 && y2.size() <= 5) {
		int xx2 = stoi(x2);
		int yy2 = stoi(y2);
		ss2 = check(1LL * xx2, 1LL * yy2);
		if (ss2 <= 1000 * 1000)
			;
		else
			ok2 = 0;
	} else {
		ok2 = 0;
	}
	if (ok1 && ok2) {
		if (ss1 < ss2)
			printf("Alice\n");
		else if (ss1 == ss2)
			printf("Draw\n");
		else
			printf("Bob\n");
	} else if (ok1 && !ok2)
		printf("Alice\n");
	else if (!ok1 && ok2)
		printf("Bob\n");
	else
		printf("Draw\n");
	return 0;
}