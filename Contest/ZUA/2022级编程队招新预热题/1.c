#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n > 19)
        printf("不合适");
    else
        printf("合适");
    return 0;
}