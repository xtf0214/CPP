#include <bits/stdc++.h>
using namespace std;

char s[1010][10];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++)
            scanf("%s", s[i] + 1);
        int ok = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i][1] == 'O' && s[i][2] == 'O') {
                s[i][1] = '+', s[i][2] = '+', ok = 1;
                break;
            }
            if (s[i][4] == 'O' && s[i][5] == 'O') {
                s[i][4] = '+', s[i][5] = '+', ok = 1;
                break;
            }
        }
        if (ok) {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                if (i != 1)
                    printf("\n");
                printf("%s", s[i] + 1);
            }
            // printf("\n");
        } else
            printf("NO");
        printf("\n");
    }
    return 0;
}