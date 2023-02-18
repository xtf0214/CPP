#include <stdio.h>
int count(int x) {
    int res = 0;
    for (; x; x /= 10)
        res += x % 10;
    return res;
}
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        int ans = count(x);
        int same = 1;
        for (int i = 2; i <= 9; i++)
            if (count(x * i) != ans) {
                same = 0;
                break;
            }
        if (same)
            printf("%d\n", ans);
        else
            printf("NO\n");
    }
    return 0;
}