#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 2 || n == 4) {
        cout << -1 << endl;
    } else if (n & 1) {
        cout << (n + 1) / 2 << endl;
        for (int i = 1; i <= (n + 1) / 2; i++)
            cout << i << " ";
    } else {
        cout << n / 2 << endl;
        cout << 0 << " ";
        for (int i = 2; i <= n / 2; i++)
            cout << i << " ";
    }
    return 0;
}