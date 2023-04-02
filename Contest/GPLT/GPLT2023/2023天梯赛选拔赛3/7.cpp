#include <bits/stdc++.h>
using namespace std;
long long f[200];
int main() {
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    int n;
    cin >> n;
    for (int i = 4; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    cout << f[n];
}