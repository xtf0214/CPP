#include <stdio.h>
int main() {
    int n, s = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        s ^= a[i];
    }
    if (s == 0) {
        printf("0");
        return 0;
    }
    for (int i = 1; i < a[0]; i++)
        for (int j = 1; j < n; j++) {
            int x = a[0] - i, y = a[j] + i;
            int t = s ^ a[0] ^ a[j] ^ x ^ y;
            if (t == 0) {
                printf("%d", i);
                return 0;
            }
        }
    printf("-1");
    return 0;
}
