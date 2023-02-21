#include <stdio.h>
#define N 100005

int n, p, q;
int arr[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", arr + i);
    scanf("%d", &p);
    for (int a, b, v; p--;) {
        scanf("%d %d %d", &a, &b, &v);
        for (int j = a; j <= b; j++)
            arr[j] += v;
    }
    scanf("%d", &q);
    for (int t; q--;) {
        scanf("%d", &t);
        printf("%d\n", arr[t]);
    }
    return 0;
}

