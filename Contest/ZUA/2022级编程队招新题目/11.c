#include <stdio.h>

int main() {
    char s[15];
    scanf("%s", s);
    int res[2] = {5, 5}, score[2] = {0, 0};
    for (int i = 0; i < 10; i++) {
        int team = i & 1;
        res[team]--;
        score[team] += s[i] - '0';
        if (score[0] + res[0] < score[1] || score[1] + res[1] < score[0]) {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
