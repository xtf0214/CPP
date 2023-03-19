#include <iostream>
using namespace std;
int a[25][25];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[j][i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
}
