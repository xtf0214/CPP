#include <stdio.h>

int isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 0 && x != 1;
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        if (isPrime(i))
            cnt++;
    printf("%d", cnt);
    return 0;
}