#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%c%c", n - 1 + 'A', n - 1 + 'a');
    return 0;
}