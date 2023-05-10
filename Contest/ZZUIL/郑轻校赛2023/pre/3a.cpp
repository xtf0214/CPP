#include <bits/stdc++.h>
using namespace std;

int a[101][101], b[101];

int main() {
    // cin >> b[1] >> b[2];
    // for (int j = 1; j <= 3; j++)
    //     for (int i = 1; i <= 2; i++)
    //         cin >> a[j][i];
    while (cin >> b[1] >> b[2] >> a[1][1] >> a[2][1] >> a[1][2] >> a[2][2] >> a[1][3] >> a[2][3]) {
        int ok = 0;
        for (int j = 1; j <= 3; j++) {
            if (a[1][j] == b[1])
                if (a[2][j] == b[2]) {
                    // printf("j : %d\n", j);
                    ok = 1;
                }
        }
        for (int j1 = 1; j1 <= 3; j1++)
            for (int j2 = j1 + 1; j2 <= 3; j2++) {
                if (a[1][j1] + a[1][j2] == b[1])
                    if (a[2][j1] + a[2][j2] == b[2]) {
                        // printf("j1 : %d, j2 : %d\n", j1, j2);
                        ok = 1;
                    }
            }
        if (a[1][1] + a[1][2] + a[1][3] == b[1])
            if (a[2][1] + a[2][2] + a[2][3] == b[2])
                ok = 1;
        if (ok)
            printf("Yes\n");
        else
            printf("No\n");
    }
}