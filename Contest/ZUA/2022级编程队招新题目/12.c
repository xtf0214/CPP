#include <stdio.h>
#define N 100005
int arr[N], d[N];
int n, p, q;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", arr + i);
    scanf("%d", &p);
    for (int i = 0, a, b, v; i < p; i++) {
        scanf("%d %d %d", &a, &b, &v);
        d[a] += v;
        d[b + 1] -= v;
    }
    for (int i = 2; i <= n; i++)
        d[i] += d[i - 1];
    scanf("%d", &q);
    for (int t; q--;) {
        scanf("%d", &t);
        printf("%d\n", arr[t] + d[t]);
    }
    return 0;
}
