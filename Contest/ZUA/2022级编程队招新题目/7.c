#include <stdio.h>
int main() {
    char s[40];
    scanf("%s", s);
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 8; j++)
            sum += (s[i * 8 + j] - 48) << (7 - j);
        printf("%d%c", sum, ".\n"[i == 3]);
    }
    return 0;
}