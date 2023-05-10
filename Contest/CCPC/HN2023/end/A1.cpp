#include <bits/stdc++.h>
using namespace std;

int n, m, z[200003];
char s[100002], p[200003];
set<char> st;

inline void manacher(int k) {
//    printf("k : %d\n", k);
//    printf("1----\n");
	st.clear();
	m = strlen(s + 1);
    if (m == 1) {
        printf("NaN\n");
		return;
    }
    if (m == 2) {
        printf("HE\n");
//        printf("---\n");
        return;
    }
    char ch = s[1];
    int ok = 1;
    for (int i = 2; i <= m; i++)
        if (s[i] != ch)
            ok = 0;
//    printf("2---\n");
    if (ok) {
        printf("HE\n");
//        printf("---\n");
        return;
    }
//    printf("3---\n");
	n = 0;
	p[++n] = '$';
//	for (int i = 1; i <= m; i++)
//		p[++n] = s[i], p[++n] = '$';
	for (int i = 1; i <= n; i++)
		cout << p[i] <<" ";
	cout << endl;
	int M = 1, R = 0;
	for (int i = 1; i  <= n; i++) {
		if (i < R)
			z[i] = min(z[M * 2 - i], R - i + 1);
		else
			z[i] = 1;
		while (i - z[i] > 0 && i + z[i] <= n && p[i - z[i]] == p[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > R)
			M = i, R = i + z[i] - 1;
	}
//	for (int i = 1; i <= n; i++) {
//		if (i > R)
//			z[i] = 1;
//		else
//			z[i] = min(M * 2 - i, R - i + 1);
//		while (i - z[i] > 0 && i + z[i] <= n && p[i - z[i]] == p[i + z[i]])
//			++z[i];
//		if (i + z[i] >= R)
//			M = i, R = i + z[i] - 1;
//	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", z[i]);
//	cout << endl;
	int mn;
	for (int i = n; i >= n / 2; i--)
		if (i + z[i] - 1 == n) {
//			if (i == n / 2 + 1)
//				continue;
			mn = i;
        }
//    printf("mn: %d\n", mn);
//    printf("4---\n");
	int l = mn - z[mn] + 1;
	if (l == 1) {
//		printf("NaN\n");
		return;
	}
    // printf("l : %d\n", l);
	for (int i = l; i; i--) {
		if (p[i] == '$')
			continue;
		if (st.count(p[i])) {
			printf("NaN\n");
			return;
		}
		st.insert(p[i]);
	}
//    printf("l : %d\n", l);
	printf("HE\n");
}

int main() {
	int t, k = 0;
	cin >> t;
	while (t--) {
		++k;
		scanf("%s", s + 1);
		manacher(k);
	}
	return 0;
}
