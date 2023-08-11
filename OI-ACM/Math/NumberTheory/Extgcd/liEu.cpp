#include <bits/stdc++.h>
using namespace std;

int extgcd(int a, int b, int &x, int &y) {
    int d;
    if (b == 0)
        x = 1, y = 0, d = a;
    else {
        d = extgcd(b, a % b, y, x); // x'  y'
        y -= a / b * x;             // y = y - a / b * x = x' - a / b * y' = y'' - a / b * y'
    }
    return d;
}

bool liEu(int a, int b, int c, int &x, int &y) {
    int d = extgcd(a, b, x, y);
    if (c % d != 0)
        return false;
    x = 1LL * x * c / d % b;
    y = 1LL * y * c / d % b;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, x, y;
        cin >> a >> c >> b;
        if (liEu(a, b, c, x, y)) {
            cout << x << '\n';
        } else {
            cout << "impossible\n";
        }
    }
}