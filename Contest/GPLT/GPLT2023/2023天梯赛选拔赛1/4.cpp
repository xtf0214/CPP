#include <iostream>
using namespace std;
int f[100005];
int main() {
    int n;
    cin >> n;
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 100;
    printf("%02d", f[n]);
    return 0;
}