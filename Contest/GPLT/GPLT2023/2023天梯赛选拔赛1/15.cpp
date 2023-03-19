#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;

int n;
int a[N];
int f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 0x3f, sizeof(f));
    for (int L = 0; L < n; L++)
        for (int i = 1, j = i + L; j <= n; i++, j++) {
            if (a[i] == a[j])
                f[i][j] = (L < 2) ? 1 : min(f[i][j], f[i + 1][j - 1]);
            for (int k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
    cout << f[1][n];
    return 0;
}