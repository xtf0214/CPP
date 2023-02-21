#include <stdio.h>

int main() {
    int n;
    long long sum = 0, mul = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++, mul *= i)
        sum += mul;
    printf("%lld", sum);
    return 0;
}
