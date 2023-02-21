#include <stdio.h>

int isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 0 && x != 1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            break;
        }
    }
    return 0;
}
